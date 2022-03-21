#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000001
int N;
long long arr[MAXN];
int Rank[MAXN];
vector<long long> cache;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        int size = cache.size() - 1;
        if (cache.empty())
        {
            cache.push_back(arr[i]);
            Rank[i] = size + 2;
        }
        else if (cache[size] < arr[i])
        {
            cache.push_back(arr[i]);
            Rank[i] = size + 2;
        }
        else if (cache[size] > arr[i])
        {
            while (size >= 0)
            {
                if (cache[size] < arr[i])
                {
                    cache[size] = arr[i];
                    break;
                }
                size--;
            }
            Rank[i] = size + 2;
        }
    }
    cout << cache.size() << endl;
    int tempRank = 0;
    for (int i = 0; i < N; i++)
    {
        if (tempRank < Rank[i])
        {
            cout << arr[i] << ' ';
            tempRank++;
        }
    }
}