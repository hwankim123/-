#include<iostream>
using namespace std;

#define MAXN 21
#define a 65

int R, C;
char adj[MAXN][MAXN];
bool visited_alphabet[30];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int result = -1;

void dfs(int y, int x, int cnt){
    if(y < 0 || y >= R || x < 0 || x >= C || visited_alphabet[adj[y][x] - a]){
        if(result < cnt) result = cnt - 1;
        return;
    }
    visited_alphabet[adj[y][x] - a] = true;
    for(int i = 0; i < 4; i++){
        dfs(y + dy[i], x + dx[i], cnt + 1);

    }
    visited_alphabet[adj[y][x] - a] = false;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> adj[i];
    }
    dfs(0, 0, 1);
    cout << result;
}