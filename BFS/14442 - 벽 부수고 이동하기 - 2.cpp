#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAXN 1001
#define INF 987654321

int N, M, K;
int adj[MAXN][MAXN];
int dist[MAXN][MAXN][11];
int result = INF;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    dist[1][1][K] = 1;
    q.push({{1, 1}, K});
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        if (y == N && x == M)
        {
            result = (result > dist[y][x][cnt]) ? dist[y][x][cnt] : result;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ty = y + dy[i];
            int tx = x + dx[i];
            if (ty >= 1 && ty <= N && tx >= 1 && tx <= M)
            {
                if (adj[ty][tx] == 1)
                {
                    if (cnt >= 1 && (dist[ty][tx][cnt - 1] == 0 || dist[ty][tx][cnt - 1] > dist[y][x][cnt] + 1))
                    {
                        dist[ty][tx][cnt - 1] = dist[y][x][cnt] + 1;
                        q.push({{ty, tx}, cnt - 1});
                    }
                }
                else
                {
                    if (dist[ty][tx][cnt] == 0 || dist[ty][tx][cnt] > dist[y][x][cnt] + 1)
                    {
                        dist[ty][tx][cnt] = dist[y][x][cnt] + 1;
                        q.push({{ty, tx}, cnt});
                    }
                }
            }
        }
    }
    if (result == INF)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            adj[i][j] = s[j - 1] - '0';
        }
    }
    bfs();
}