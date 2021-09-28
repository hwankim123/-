#include<iostream>
#include<vector>
using namespace std;

const int clear = 2;
int N, M, y, x, d;
vector<vector<int> > adj;

int dy[4] = {-1, 0, 1, 0}; // 북 -> 서 -> 남 -> 동
int dx[4] = {0, -1, 0, 1};

int solve(){
    int count = 0;
    int dir = 0;
    switch(d){
        case 0:
            dir = 0;
            break;
        case 1:
            dir = 3;
            break;
        case 2:
            dir = 2;
            break;
        case 3:
            dir = 1;
            break;
    }
    
    while(true){
        if(adj[y][x] != clear){
            adj[y][x] = clear;
            count++;
        }
        int tempDir = (dir + 1) % 4;
        bool moved = false;
        for(tempDir; tempDir != dir; tempDir = (tempDir + 1) % 4){
            int ty = y + dy[tempDir];
            int tx = x + dx[tempDir];
            if(adj[ty][tx] == 0){
                dir = tempDir; // 회전
                y = ty; // 전진
                x = tx;
                moved = true;
                break;
            }
        }
        if(!moved){
            if(adj[y + dy[dir]][x + dx[dir]] == 0){
                y = y + dy[dir]; // 전진
                x = x + dx[dir];
            }
            else{
                y -= dy[dir];
                x -= dx[dir];
                if(adj[y][x] == 1){
                    break;
                }
            }
        }
    }
    return count;
}

int main(){
    cin >> N >> M;
    cin >> y >> x >> d;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    cout << solve();
}