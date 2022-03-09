#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAXN 300001
#define INF 987654321

int N, M, K, X;
vector<int> adj[MAXN];

void bfs(){
    queue<int>q;
    vector<int> dist(MAXN, INF);
    dist[X] = 0;
    q.push(X);
    
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            if(dist[there] == INF){
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
    bool flag = false;
    for(int i = 1; i <= N; i++){
        if(dist[i] == K){
            flag = true;
            cout << i << '\n';
        }
    }
    if(!flag){
        cout << -1;
    }
}

int main(){
    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bfs();
}