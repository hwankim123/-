#include<iostream>
#include<vector>
using namespace std;

int adj[101][101];
int N;
pair<int, int> yx[20];
int dir[20];
int g[20];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void draw(){
    for(int i = 0; i < N; i++){
        int y = yx[i].first;
        int x = yx[i].second;
        adj[y][x] = 1;
        y += dy[dir[i]];
        x += dx[dir[i]];
        adj[y][x] = 1;
        vector<int> d(1, dir[i]);
        int n = 1; // 드래곤 커브 점 찍는 횟수
        for(int j = 0; j < g[i]; j++){ // 0세대 : 0 ~ 0, 1세대 : 0 ~ 1 ... 
            for(int k = n - 1; k >= 0; k--){
                int t = (d[k] + 1) % 4;
                y += dy[t];
                x += dx[t];
                adj[y][x] = 1;
                d.push_back(t);
            }
            n *= 2;
        }
    }
}

int solve(){
    int result = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(adj[i][j] == 1 && adj[i + 1][j] == 1 && adj[i][j + 1] == 1 && adj[i + 1][j + 1] == 1){
                result++;
            }
        }
    }
    return result;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int y, x;
        cin >> x >> y >> dir[i] >> g[i];
        yx[i] = make_pair(y, x);
    }
    draw();
    cout << solve();
}