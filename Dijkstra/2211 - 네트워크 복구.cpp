#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int MAX_V = 1001, INF = 2000000000;
int n, m;
vector<pair<int, int> > adj[MAX_V];
vector<int> parent;
int numLine;

void dijkstra(){
    priority_queue<pair<int, int> > pq;
    vector<int> dist(MAX_V, INF);
    parent = vector<int>(MAX_V, INF);
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] > cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int thereCost = adj[here][i].first;
            int there = adj[here][i].second;
            if(dist[there] > thereCost + cost){
                dist[there] = thereCost + cost;
                pq.push(make_pair(-dist[there], there));
                parent[there] = here;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    dijkstra();
    string s;
    for(int i = 1; i <= n; i++){
        if(parent[i] != INF){
            numLine++;
            s += to_string(parent[i]) + ' ' + to_string(i) + '\n';
        }
    }
    cout << numLine << endl;
    cout << s;
}