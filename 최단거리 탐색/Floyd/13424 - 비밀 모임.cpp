#include <iostream>
using namespace std;

#define MAXN 101
#define INF 987654321

int T;
int N, M;
int adj[MAXN][MAXN];
int K;
int kLoc[MAXN];

int main()
{
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N >> M;
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= N; k++)
            {
                adj[j][k] = INF;
            }
        }
        for (int j = 0; j < M; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (adj[a][b] > c || adj[b][a] > c)
            {
                adj[a][b] = c;
                adj[b][a] = c;
            }
        }
        cin >> K;
        for (int k = 0; k < K; k++)
        {
            cin >> kLoc[k];
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    if (j == k)
                        continue;
                    if (adj[j][i] == INF || adj[i][k] == INF)
                        continue;
                    if (adj[j][k] > adj[j][i] + adj[i][k])
                    {
                        adj[j][k] = adj[j][i] + adj[i][k];
                    }
                }
            }
        }
        int sum = INF;
        int room = INF;
        for (int i = 1; i <= N; i++)
        {
            int temp = 0;
            for (int k = 0; k < K; k++)
            {
                int start = (kLoc[k] < i) ? kLoc[k] : i;
                int finish = (kLoc[k] > i) ? kLoc[k] : i;

                if (start == finish)
                    continue;
                temp += adj[start][finish];
            }
            if (sum > temp)
            {
                room = i;
                sum = temp;
            }
            else if (sum == temp)
            {
                if (room > i)
                {
                    room = i;
                }
            }
        }
        cout << room << '\n';
    }
}