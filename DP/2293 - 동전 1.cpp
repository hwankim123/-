#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 101
#define MAXK 10001

int N, K;
int cache[100001];
int coins[MAXN];

int solve(int exchange, int coinIdx)
{
    // cout << exchange << ' ' << coinIdx << endl;
    if (exchange < 0)
    {
        return 0;
    }
    if (exchange == 0)
    {
        return 1;
    }
    if (exchange != 0 && coinIdx == N - 1)
    {
        if (exchange % coins[coinIdx] == 0)
            return 1;
    }
    if (cache[exchange] != 0)
    {
        return cache[exchange];
    }
    // 이부분고치면될듯
    int sum = 0;
    for (int i = coinIdx; i < N; i++)
    {
        if (exchange - coins[i] >= 0)
        {
            sum += solve(exchange - coins[i], i);
        }
    }
    // cout << "cache updated " << "exchange : " << exchange << ' ' << sum << endl;
    return cache[exchange] += sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    sort(coins, coins + MAXN, greater<>());
    cout << solve(K, 0);
}