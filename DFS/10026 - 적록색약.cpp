#include<vector>
#include<iostream>
#include<string>
using namespace std;

int n;
vector<vector<char> >adj(100, vector<char>(100, 'B'));
vector<vector<bool> >visited;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(int y, int x, int c){
    if(y < 0 || y >= n || x < 0 || x >= n) return;
    if(visited[y][x]) return;
    if(adj[y][x] != c) return;
    visited[y][x] = true;
    for(int i = 0; i < 4; i++){
        dfs(y + dy[i], x + dx[i], adj[y][x]);
    }
    if(adj[y][x] == 'R') adj[y][x] = 'G';
}

int result;
void dfs_All(){
    result = 0;
    visited = vector<vector<bool> >(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs(i, j, adj[i][j]);
                result++;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            adj[i][j] = s[j];
        }
    }
    dfs_All();
    cout << result << ' ';
    dfs_All();
    cout << result;
}