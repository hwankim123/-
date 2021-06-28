#include<iostream>
#include<vector>
using namespace std;

int N, _min = 2017103979, _max = 1;
vector<vector<int>> adj(101, vector<int>(101, 0));
vector<vector<bool>> visited;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, int d){
    if(y < 0 || y >= N || x < 0 || x >= N) return;
    if(visited[y][x]) return;
    visited[y][x] = true;
    if(adj[y][x] <= d) return;
    for(int i = 0; i < 4; i++) dfs(y + dy[i], x + dx[i], d);
}

int dfsAll(int depth){
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && adj[i][j] > depth){
                dfs(i, j, depth);
                count++;
            }
        }
    }
    return count;
}

int solve(){
    int result = 1;
    for(int i = _min; i < _max; i++){
        int temp = dfsAll(i);
        if(result < temp) result = temp;
    }
    return result;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
            if(_min > adj[i][j]) _min = adj[i][j];
            if(_max < adj[i][j]) _max = adj[i][j];
        }
    }
    cout << solve();
}