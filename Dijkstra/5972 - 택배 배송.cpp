#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAXN 50001
#define INF 987654321

int N, M;
vector<pair<int, int> >adj[MAXN];

void dijkstra(){
    priority_queue<pair<int, int> >pq;
    vector<int> dist(N + 1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].second;
            int thereCost = adj[here][i].first;
            if(dist[there] > cost + thereCost){
                dist[there] = cost + thereCost;
                pq.push({-dist[there], there});
            }
        }
    }
    cout << dist[N];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dijkstra();
}