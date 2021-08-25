#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_V = 2001, INF = 200000000;
vector<bool> tAry;
priority_queue<int, vector<int>, greater<int> > result;
int T, n, m, t, s, g, h;

void dijkstra(vector<pair<int, int> > adj[]){
    priority_queue<pair<int, int>>pq;
    vector<int> dist(MAX_V, INF);
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(tAry[here] && cost % 2 == 1 && dist[here] == cost){
            result.push(here);
            tAry[here] = false;
        }
        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int thereCost = adj[here][i].first;
            int there = adj[here][i].second;
            if(dist[there] > cost + thereCost){
                dist[there] = cost + thereCost;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
}

int main(){
    cin >> T;
    for(int j = 0; j < T; j++){
        vector<pair<int, int> > adj[MAX_V];
        tAry = vector<bool>(MAX_V, false);
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for(int i = 0; i < m; i++){
            int a, b, d;
            cin >> a >> b >> d;
            d *= 2;
            if((a == g && b == h) || (b == g && a == h)) d -= 1; // 확인된 경로만 홀수
            adj[a].push_back(make_pair(d, b));
            adj[b].push_back(make_pair(d, a));
        }
        for(int i = 0; i < t; i++){
            int x;
            cin >> x;
            tAry[x] = true;
        }
        dijkstra(adj);
        while(!result.empty()){
            cout << result.top() << ' ';
            result.pop();
        }
        cout << endl;
    }

}