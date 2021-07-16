#include<iostream>
#include<vector>
#include<list>
using namespace std;

int K, V, E;
vector<list<int> >adj;
vector<int> visited;

bool dfs(int previous, int here){
    if(visited[here] != -1)
        if(previous == visited[here]) return false;
        else return true;
    if(previous == 1) visited[here] = 2;
    else if(previous == 2) visited[here] = 1;

    bool result = true;
    for(list<int>::iterator it = adj[here].begin(); it != adj[here].end(); it++){
        result = result && dfs(visited[here], *it);
        if(!result) return false;
    }
    return result;
}

bool dfs_All(){
    visited = vector<int>(V + 1, -1);
    bool result = true;
    for(int i = 1; i <= V; i++){
        if(visited[i] == -1){
            visited[i] = 1;
            for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
                result = result && dfs(visited[i], *it);
                if(!result) return false;
            }
        }
    }
    return result;
}

int main(){
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> V >> E;
        adj = vector<list<int> >(V + 1, list<int>());
        for(int j = 0; j < E; j++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(dfs_All()) cout << "YES\n";
        else cout << "NO\n";
    }
}