#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1000000000;
const int MAX_V = 10001;
int N, D;
vector<pair<int, int> > adj[MAX_V];
vector<int> result;

vector<int> dijkstra(){
    vector<int> dist(MAX_V, INF);
    dist[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost) {
            continue;
        }

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].second;
            int thereCost = adj[here][i].first;
            if(there > D) {
                continue;
            }
            if(cost + thereCost < dist[there]){
                dist[there] = cost + thereCost;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
    return dist;
}


int main(){
    cin >> N >> D;
    vector<bool> V(MAX_V, false);
    priority_queue<int> vpq;
    vpq.push(0);
    vpq.push(D);
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(b > D) continue;
        adj[a].push_back(make_pair(c, b)); 
        if(!V[a]){
            V[a] = true;
            vpq.push(a);
        }
        if(!V[b]){
            V[b] = true;
            vpq.push(b);
        }
    }
    while(!vpq.empty()){
        int b = vpq.top();
        vpq.pop();
        if(vpq.empty()) break;
        int a = vpq.top();
        adj[a].push_back(make_pair(b - a, b));
    }
    result = dijkstra();
    cout << result[D];
}