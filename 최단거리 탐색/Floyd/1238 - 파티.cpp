#include <iostream>
using namespace std;

#define INF 987654321
#define MAXN 1001

// Floyd보다 Dijkstra N번 시행하는 것이 더 수행시간이 짧게 나옴

int N, M, X;
int adj[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    for (int i = 1; i <= N; i++)
    { // 경유 노드
        for (int j = 1; j <= N; j++)
        { // 시작 노드
            for (int k = 1; k <= N; k++)
            { // 끝 노드
                if (j == k)
                    continue;
                if (adj[j][i] == INF || adj[i][k] == INF)
                    continue;
                if (adj[j][k] > adj[j][i] + adj[i][k])
                    adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == X)
            continue;
        if (adj[i][X] + adj[X][i] > result)
            result = adj[i][X] + adj[X][i];
    }
    cout << result;
}