#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 10001
#define INF 987654321
int T;
int n, d, c;

void dijkstra(vector<pair<int, int> > adj[], int src){
    priority_queue<pair<int, int> >pq;
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int thereCost = adj[here][i].second;
            if(dist[there] > cost + thereCost){
                dist[there] = cost + thereCost;
                pq.push({-dist[there], there});
            }
        }
    }
    int cnt = 0, time = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) continue;
        cnt++;
        if(time < dist[i]) time = dist[i];
    }cout << cnt << ' ' << time << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++){
        vector<pair<int, int> > adj[MAXN];
        cin >> n >> d >> c;
        for(int j = 0; j < d; j++){
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }
        dijkstra(adj, c);
    }
}