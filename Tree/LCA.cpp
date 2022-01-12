#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 20

using namespace std;
int N, M;
int a, b;
int dp[MAX + 1][100001]; // [i][j]에 대하여, node j의 i 번째 부모 node를 저장
int depth[100001];
bool isVisited[100001];
vector<int> adj[100001];

void dfs(int here, int d)
{
    isVisited[here] = true;
    depth[here] = d;
    int there;
    for (int i = 0; i < adj[here].size(); i++)
    {
        there = adj[here][i];
        if (isVisited[there])
            continue;
        dp[0][there] = here;
        dfs(there, d + 1);
    }
}
void setDP()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j <= N; j++)
        { // i-1번째 부모
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}
int lca(int x, int y)
{
    // 깊이가 다르다면, 깊이가 더 깊은 쪽을 y로 설정
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = MAX; i >= 0; i--)
    {
        if (depth[y] - depth[x] >= (1 << i))
            y = dp[i][y];
    }
    if (x == y)
        return x;

    for (int i = MAX; i >= 0; i--)
    {
        if (dp[i][x] != dp[i][y])
        {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(isVisited, 0, sizeof(isVisited));
    dfs(1, 1);

    setDP();

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}