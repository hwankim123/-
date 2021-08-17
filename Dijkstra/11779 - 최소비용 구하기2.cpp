#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int MAX_V = 1001, INF = 1000000000;
vector<pair<int, int> > adj[MAX_V];
vector<int> parent(MAX_V, 0);
int n, m, start, finish;

vector<int> dijkstra(){
    vector<int> dist(MAX_V, INF);
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int thereCost = adj[here][i].first;
            int there = adj[here][i].second;
            if(dist[there] > cost + thereCost){
                dist[there] = cost + thereCost;
                pq.push(make_pair(-dist[there], there));
                parent[there] = here;
            }
        }
    }
    return dist;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
    }
    cin >> start >> finish;
    vector<int> result = dijkstra();
    int path = finish;
    string s = ' ' + to_string(path);
    int count = 1;
    while(path != start){
        s = ' ' + to_string(parent[path]) + s;
        path = parent[path];
        count++;
    }
    cout << result[finish] << endl << count << endl << s.substr(1, s.size() - 1);
}