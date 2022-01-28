#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define INF 987654321
#define MAXN 101
int n, m;            // n : 노드 개수 / m : 간선 개수
int adj[MAXN][MAXN]; // 최단 거리 dp 배열
int via[MAXN][MAXN]; // via[y][x] : y에서 x까지 가는 최당 경로가 경유하는 점 중 가장 번호가 큰 정점

// 최단 경로를 찾는 알고리즘
// y --> x까지의 최단 경로를 알고 싶으면 y --> w 까지의 경로, w --> x까지의 경로를 구한 뒤 합치면 된다.
void reconstruct(int y, int x, vector<int> &path)
{
    if (via[y][x] == -1)
    {
        path.push_back(y);
        if (y != x)
            path.push_back(x);
    }
    else
    {
        int w = via[y][x];
        reconstruct(y, w, path);
        path.pop_back(); // w가 중복으로 들어가기 때문에 지운다.
        reconstruct(w, x, path);
    }
}

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
                // 시작 노드에서 경유 노드의 간선 정보가 없을 때 혹은
                // 경유 노드에서 끝 노드의 간선 정보가 없을 때 continue
                if (adj[j][i] == INF || adj[i][k] == INF)
                    continue;
                // 누적된 시작 노드에서 끝 노드까지의 cost보다 더 짧은 경로가 있을 때 update
                if (adj[j][k] > adj[j][i] + adj[i][k])
                    adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }

    cout << "<< 최단 거리 >>" << endl;
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

    cout << "<< 경로 >>" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << "- ";
            else
            {
                vector<int> path;
                reconstruct(i, j, path);
                for (int k = 0; k < path.size(); k++)
                {
                    cout << path[k] << ' ';
                }
            }
        }
        cout << endl;
    }
}