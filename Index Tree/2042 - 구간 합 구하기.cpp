#include <iostream>
using namespace std;

#define MAXN 20

int B, N, M, K, a; // M : 수 변경 횟수, K : 구간 합 횟수
long long arr[1 << (MAXN + 1)];

long long cal(int x, int y)
{
    int lo = x + B - 1, hi = y + B - 1;
    long long sum = 0;
    while (lo <= hi)
    {
        if (lo % 2 == 1)
        {
            sum += arr[lo];
        }
        if (hi % 2 == 0)
        {
            sum += arr[hi];
        }
        lo = (lo + 1) / 2;
        hi = (hi - 1) / 2;
    }
    return sum;
}

void update(int old, long long val)
{
    int idx = old + B - 1;
    arr[idx] = val;
    while ((idx /= 2) > 0)
    {
        arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (B = 1; B < N; B <<= 1)
        ;
    for (int i = B; i < N + B; i++) // 데이터가 들어가는 시작 인덱스는 [2^k]
    {
        cin >> arr[i];
    }
    for (int i = B - 1; i > 0; i--) // 트리의 인덱스는 [1] ~ [2^k - 1]
    {
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }
    for (int i = 0; i < M + K; i++)
    {
        long long b, c;
        cin >> a >> b >> c;
        if (a == 1)
        { // 수 변경
            update(b, c);
        }
        else
        { // 구간 합
            cout << cal(b, c) << '\n';
        }
    }
}