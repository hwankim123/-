#include <iostream>
using namespace std;

#define MAXN 1100
#define INF 987654321

int n, m;
int arr[MAXN][MAXN];
int cache[MAXN][MAXN];

int checkCache(int i, int j)
{
    int min = INF;
    if (min > cache[i + 1][j + 1])
    {
        min = cache[i + 1][j + 1];
    }
    if (min > cache[i][j + 1])
    {
        min = cache[i][j + 1];
    }
    if (min > cache[i + 1][j])
    {
        min = cache[i + 1][j];
    }
    cout << "min" << min << endl;
    return min;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char input[MAXN];
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            arr[i + 1][j + 1] = input[j] - '0';
        }
    }
    int result = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = m; j > 0; j--)
        {
            if (arr[i][j] == 0)
            {
                continue;
            }
            //cout << i << ' ' << j << endl;
            cache[i][j] = checkCache(i, j) + 1;
            //cout << "cache i, j" << i << ' ' << j << "   " << cache[i][j] << endl;
            if (cache[i][j] > result)
                result = cache[i][j];
        }
    }
    cout << result * result;
}