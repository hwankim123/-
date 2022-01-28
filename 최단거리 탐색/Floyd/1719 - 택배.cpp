#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 201
#define INF 987654321

int n, m;
int adj[MAXN][MAXN];
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

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    memset(via, -1, sizeof(via));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (adj[j][i] == INF || adj[i][k] == INF)
                    continue;
                if (adj[j][k] > adj[j][i] + adj[i][k])
                {
                    via[j][k] = i;
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }
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
                cout << path[1] << ' ';
            }
        }
        cout << endl;
    }
}