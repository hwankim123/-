#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 100001 
#define INF 987654321

int V, E, K;
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > adj[MAXN];
vector<int> dist(MAXN, INF);

int main(){
    cin >> V >> E >> K;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
    }

    dist[K] = 0;
    pq.push(make_pair(0, K));

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
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}