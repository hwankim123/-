#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MAXN 100001
int coin[MAXN];
int cache[MAXN];
vector<int> lastElem; // lastElem[i] : 가장 긴 증가하는 부분수열의 길이가 i일 때, 해당 부분수열의 마지막 element를 저장
int N;

int lowerBound(int lo, int hi, int num)
{
    int mid;
    while (hi - lo > 0)
    {
        mid = (lo + hi) / 2;
        if (lastElem[mid] < num)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return hi;
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        if (lastElem.size() == 0 || coin[i] > lastElem[lastElem.size() - 1])
        {
            lastElem.push_back(coin[i]);
        }
        else
        {
            int idx = lowerBound(0, lastElem.size(), coin[i]);
            lastElem[idx] = coin[i];
        }
    }
    cout << lastElem.size() << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N)
    {
        memset(cache, 0, MAXN);
        lastElem = vector<int>(0, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> coin[i];
        }

        solve();
    }
}
