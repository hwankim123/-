#include<iostream>
#include<vector>
#include<list>
using namespace std;

int N;
vector<list<int> > adj;
vector<int> visited;

// 노드 x를 방문. 이 때 부모 노드는 y
void dfs(int y, int x){
    visited[x] = y;
    for(list<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++){
        if(visited[*it] == -1){
            dfs(x, *it);
        }
    }
}

void dfs_All(){
    visited[1] = 0;
    for(list<int>::iterator it = adj[1].begin(); it != adj[1].end(); it++){
        if(visited[*it] == -1){
            dfs(1, *it);
        }
    }
}

int main(){
    cin >> N;
    adj = vector<list<int> >(N + 1, list<int>());
    visited = vector<int>(N + 1, -1);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_All();
    for(int i = 2; i <= N; i++){
        cout << visited[i] << '\n';
    }
}