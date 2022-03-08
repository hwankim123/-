#include<iostream>
#include<vector>
using namespace std;

#define MAXN 100001

int N, S, D;
vector<int> adj[MAXN];
vector<bool> visited;
int result;

int dfs(int here){
    if(visited[here]){
        return 0;
    }
    visited[here] = true;
    int depth = 1;
    for(int i = 0; i < adj[here].size(); i++){
        int temp = dfs(adj[here][i]);
        if(temp > D){
            result += 2;
        }
        if(depth < ++temp) depth = temp;
    }
    cout << endl;
    return depth;
}

int main(){
    cin >> N >> S >> D;
    visited = vector<bool>(N + 1, false);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(S);
    cout << result;
}