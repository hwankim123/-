#include <iostream>
using namespace std;

#define MAXK 10001
#define MAXN 100

int N, K;
int cache[MAXK];
int coins[MAXN];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    cache[0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i]; j <= K; j++)
        {
            if (j >= coins[i])
            {
                cache[j] += cache[j - coins[i]];
            }
        }
    }
    cout << cache[K];
}