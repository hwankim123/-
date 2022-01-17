#include<iostream>
using namespace std;

#define MAXN 201
#define MAXM 1001

int N, M;
int adj[MAXN][MAXN];
bool visited[MAXN];
int path[MAXM];

void dfs(int here){
    if(visited[here]) return;
    //cout << "herhe : " << here << endl;
    visited[here] = true;
    for(int i = 1; i <= N; i++){
        if(adj[here][i]) dfs(i);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a; cin >> a;
            if(a == 1){
                adj[i][j] = a;
                adj[j][i] = a;
            }
        }
    }
    for(int i = 0; i < M; i++){
        cin >> path[i];
    }
    dfs(path[0]);
    for(int i = 0; i < M; i++){
        if(!visited[path[i]]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}