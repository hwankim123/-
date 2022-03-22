#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAXN 1001

int N;
int arr[MAXN];
int updatedIdx[MAXN]; // 역추적에 이용됨
vector<int> cache;

// 가장 어려웠던 반례
// 6
//
// 1 3 5 7 2 3
// 오답 : 4
//        1 2 3 5 7
// 역추적을 위해 parent배열을 사용하는 것이 아니라 updatedIdx배열을 사용함.
// updatedIdx[i] : arr[i]의 값이 cache의 어느 index를 update 했는지, 그 index가 저장된다.
// 역추적 방법 : updatedIdx[maxIdx]가 최대가 되게 하는 index인 maxIdx를 기억한 후, maxIdx에서 0까지 for loop을 돌면서
// arr[i] < arr[maxIdx] && cache[i] + 1 == cache[maxIdx] 을 만족하는 arr[i]를 stack에 push.
// pop 하면서 출력

// lower bound : 원하는 값 num 이상이 처음 나오는 위치를 찾는 것
// algorithm의 lower_bound를 사용해도 됨
int lowerBound(int lo, int hi, int num)
{
    int mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (num > cache[mid])
        {
            lo = mid + 1;
        }
        else
        {
            // 찾고자 하는 수보다 배열의 수가 더 클 때 끝 값을 포함하는 이유
            // --> 원하는 값 "이상"인 위치를 찾는 것이기 때문.
            // --> 끝 값이 lower bound일 수도 있기 때문이다.
            hi = mid;
        }
    }
    return hi;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cache = vector<int>(0, 0);
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 0; i < N; i++)
    {
        if (cache.empty() || cache[cache.size() - 1] < arr[i])
        {
            cache.push_back(arr[i]);
            updatedIdx[i] = cache.size() - 1;
        }
        else
        {
            int idx = lowerBound(0, cache.size() - 1, arr[i]);
            cache[idx] = arr[i];
            updatedIdx[i] = idx;
        }
        if (maxLen < updatedIdx[i])
        {
            maxLen = updatedIdx[i];
            maxIdx = i;
        }
    }
    cout << cache.size() << "\n";
    stack<int> s;
    s.push(arr[maxIdx]);
    for (int i = maxIdx - 1; i >= 0; i--)
    {
        if (arr[i] < arr[maxIdx] && updatedIdx[i] + 1 == updatedIdx[maxIdx])
        {
            maxIdx = i;
            s.push(arr[i]);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}