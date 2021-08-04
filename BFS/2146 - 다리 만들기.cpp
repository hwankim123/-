#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 123456789;
int N;
vector<vector<int> >adj;
vector<vector<bool> >visited;
queue<pair<int, int> >boundQ;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int land = 1;

bool IntoBound(int y, int x){
    return y < N && y >= 0 && x < N && x >= 0;
}
void bfs_land(int sy, int sx){
    visited[sy][sx] = true;
    adj[sy][sx] = land;
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        bool isBoundary = false;
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(IntoBound(ty, tx) && !visited[ty][tx]){
                if(adj[ty][tx] == 1){
                    q.push(make_pair(ty, tx));
                    visited[ty][tx] = true;
                    adj[ty][tx] = land;
                }
                else if(adj[ty][tx] == 0){
                    isBoundary = true;
                }
            }
        }
        if(isBoundary) {
            boundQ.push(make_pair(y, x));
        }
    }
}

int bfs_bridge(int sy, int sx){
    vector<vector<int> >dist = vector<vector<int> >(N, vector<int>(N, -1));
    dist[sy][sx] = 0;
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    int result = INF;
    bool cont = false;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(cont) continue;
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(IntoBound(ty, tx) && dist[ty][tx] == -1){
                if(adj[ty][tx] == 0){
                    q.push(make_pair(ty, tx));
                    dist[ty][tx] = 1 + dist[y][x];
                }
                else if(adj[ty][tx] != adj[sy][sx]){
                    result = dist[y][x];
                    cont = true;
                }
            }
        }
    }
    return result;
}

void solve(){
    visited = vector<vector<bool> >(N, vector<bool>(N, false));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++ ){
            if(!visited[i][j] && adj[i][j] == 1){
                bfs_land(i, j);
                land++;
            }
        }
    }
    int result = INF;
    while(!boundQ.empty()){
        int sy = boundQ.front().first;
        int sx = boundQ.front().second;
        boundQ.pop();
        int temp = bfs_bridge(sy, sx);
        if(temp < result) result = temp;
    }
    cout << result;
}

int main(){
    cin >> N;
    adj = vector<vector<int> >(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++ ){
            cin >> adj[i][j];
        }
    }
    solve();
}