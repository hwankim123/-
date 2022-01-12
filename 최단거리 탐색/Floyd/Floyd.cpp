#include <iostream>
using namespace std;

#define INF 987654321
#define MAXN 101
int n, m;            // n : 노드 개수 / m : 간선 개수
int adj[MAXN][MAXN]; // 최단 거리 dp 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 배열 초기화
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        // a --> b 간선의 cost는 c이다.
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > c)
        {
            adj[a][b] = c;
        }
    }

    // Floyd
    for (int i = 1; i <= n; i++) // 경유 노드 i
    {
        for (int j = 1; j <= n; j++) // 시작 노드 j
        {
            for (int k = 1; k <= n; k++) // 끝 노드 k
            {
                // 시작 노드와 끝 노드가 같을 때 continue
                if (j == k)
                    continue;
                // 시작 노드에서 경유 노드의 간선 정보가 없을 때
                // 경유 노드에서 끝 노드의 간선 정보가 없을 때 continue
                if (adj[j][i] == INF || adj[i][k] == INF)
                    continue;
                // 누적된 시작 노드에서 끝 노드까지의 cost보다 더 짧은 경로가 있을 때 update
                if (adj[j][k] > adj[j][i] + adj[i][k])
                    adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << adj[i][j] << ' ';
            }
        }
        cout << "\n";
    }
}