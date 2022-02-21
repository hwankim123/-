#include<iostream>
#include<memory.h>
using namespace std;

#define MAXN 501

int M, N;
int adj[MAXN][MAXN];
int cache[MAXN][MAXN];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int solve(int y, int x){
    if(y == M - 1 && x == N - 1){
        return 1;
    }
    if(cache[y][x] != -1){
        return cache[y][x];
    }
    cache[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];
        if(ty >= 0 && ty < M && tx >= 0 && tx < N && adj[y][x] > adj[ty][tx]){
            cache[y][x] += solve(ty, tx);
        }
    }
    return cache[y][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    cout << solve(0, 0);
}