#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MAXN 10000

int T;
int N, K;
vector<int> cache;

int lowerBound(int lo, int hi, int num)
{
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (num <= cache[mid])
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return hi;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cache = vector<int>(0, 0);
        cin >> N >> K;
        for (int j = 0; j < N; j++)
        {
            int coin;
            cin >> coin;
            if (cache.empty() || cache[cache.size() - 1] < coin)
            {
                cache.push_back(coin);
            }
            else
            {
                int idx = lowerBound(0, cache.size() - 1, coin);
                cache[idx] = coin;
            }
        }
        cout << "Case #" << i + 1 << "\n";
        if (K > cache.size())
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }
}