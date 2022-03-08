#include<iostream>
#include<vector>
using namespace std;

#define MAXN 2001

int N, M;
vector<int> adj[MAXN];
vector<bool> visited;
int result;

void dfs(int here, int cnt){
    if(visited[here] || result == 1){
        return;
    }
    if(cnt == 5){
        result = 1;
        return;
    }
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); i++){
        dfs(adj[here][i], cnt + 1);
    }
    visited[here] = false;
}

void solve(){
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(result == 1){
            cout << result;
            flag = true;
            break;
        }
        visited = vector<bool>(N, false);
        dfs(i, 1);
    }
    if(!flag){
        cout << result;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
}