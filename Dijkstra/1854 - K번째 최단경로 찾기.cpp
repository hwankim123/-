#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
#define MAXN 1001
#define MAXK 101

/*
*	k번째 최단 경로
*
*	i --> i로 가는 최단 경로는 0이지만, k번째 최단경로는 0이 아닐 수 있음
*	k번째 최단경로에는 같은 정점이 여러번 포함될 수 있다.
*
*	dist 배열에 priority queue를 적용. pq의 크기가 k가 되기 전까진 그냥 push. k가 넘어가면 무시??
*/

int n, m, k;
vector<pair<int, int>> adj[MAXN];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    vector<priority_queue<int>> dist = vector<priority_queue<int>>(MAXN, priority_queue<int>());
    pq.push({0, 1});
    dist[1].push(0); // node 1의 1번째 최단거리는 0

    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        // dist가 cost보다 이미 짧은 경우 continue였음

        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].second;
            int thereCost = adj[here][i].first;

            if (dist[there].size() < k)
            {
                dist[there].push(cost + thereCost);
                pq.push({-(cost + thereCost), there});
            }
            else if (dist[there].top() > cost + thereCost)
            { // 부등호를 >=로 하는게 논리상 맞는거같은데 > 도 맞고, 심지어 시간도 적게 걸림
                dist[there].pop();
                dist[there].push(cost + thereCost);
                pq.push({-(cost + thereCost), there});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() < k)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist[i].top() << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dijkstra();
}
