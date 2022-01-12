#include <iostream>
#include <queue>
using namespace std;

#define MAXN 500
#define INF 987654321

/*
리뷰

idea
거의 최단 경로 : 최단 경로에 포함되지 않는 도로로만 이루어진 경로들 중 가장 짧은 경로
 - 최단 경로 그 자체를 알 필요가 있음
 - 최단 경로를 무시하는 다익스트라를 다시 시행
 - 어떻게 최단 경로를 무시할까?


첫 번째 dijkstra : 최단 경로를 찾을 때 마다 path에 저장
 - path : node i의 parent를 저장
 - parameter로 들어가는 second는 dijkstra 횟수가 두번째인지를 넘겨줌
 - 이 때 인접 노드까지의 거리를 비교할 때 ==연산자도 허용해줬는데, 이거때문에 시간초과(메모리 초과)가 뜸.
 - - 그래서 ==일 때에는 path를 갱신하고, < 일때는 dijkstra 코드가 실행되게 해줘야함

makeBest : 최단 경로임을 저장하는 best 배열을 초기화함

두 번째 dijkstra : best[i][j]가 true일 경우를 배제하여 dijkstra를 진행

 * 주의할 점 : 앞서 말한 시간초과 및 각 테스트 케이스 마다 자료구조 초기화해주기
 * 코드 리팩토링 필요

*/

int N, M, S, D;
int adj[MAXN][MAXN];
priority_queue<pair<int, int>> pq;
queue<pair<int, int>> path[MAXN];
bool best[MAXN][MAXN];
int dist[MAXN];

void dijkstra(bool second)
{
    for (int i = 0; i < N; i++)
    {
        if (!second)
        {
            while (!path[i].empty())
            {
                path[i].pop();
            }
            for (int j = 0; j < N; j++)
            {
                best[i][j] = false;
            }
        }
        dist[i] = INF;
    }
    dist[S] = 0;
    pq.push(make_pair(0, S));
    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < N; i++)
        {
            int there, thereCost;
            if (adj[here][i] != INF)
            {
                there = i;
                thereCost = adj[here][i];
                if (dist[there] >= cost + thereCost)
                {
                    if (!best[there][here] && dist[there] > cost + thereCost)
                    {
                        dist[there] = cost + thereCost;
                        pq.push(make_pair(-dist[there], there));
                    }
                    if (!second)
                    {
                        if (path[there].empty())
                        {
                            path[there].push(make_pair(dist[there], here));
                        }
                        else
                        {
                            if (path[there].front().first > dist[there])
                            {
                                while (!path[there].empty())
                                {
                                    path[there].pop();
                                }
                                path[there].push(make_pair(dist[there], here));
                            }
                            else if (path[there].front().first == dist[there])
                            {
                                path[there].push(make_pair(dist[there], here));
                            }
                        }
                    }
                }
            }
        }
    }
}

void makeBest(int here)
{
    while (!path[here].empty())
    {
        int there = path[here].front().second;
        path[here].pop();
        if (best[here][there])
            continue;
        best[here][there] = true;
        makeBest(there);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = INF;
            }
        }

        cin >> S >> D;
        for (int i = 0; i < M; i++)
        {
            int U, V, P;
            cin >> U >> V >> P;
            adj[U][V] = P;
        }

        dijkstra(false);
        makeBest(D);

        dijkstra(true);
        if (dist[D] == INF)
            cout << -1 << '\n';
        else
            cout << dist[D] << '\n';
    }
}