#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = -1000000000;
int N, M, H, W, sr, sc, fr, fc;
vector<vector<int> > adj;
vector<vector<int> > dist; 

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool promising(int y, int x){
    return (1 <= y && y <= N - H + 1) && (1 <= x && x <= M - W + 1);
}

void bfs(){
    queue<pair<int, int> >q;
    q.push(make_pair(sr, sc));
    dist = vector<vector<int> > (N + 1, vector<int>(M + 1, INF));
    dist[sr][sc] = 0;
    bool found = false;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        // cout << y << ' ' << x << endl;
        q.pop();
        if(dist[y][x] == -1) continue;

        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(promising(ty, tx) && dist[ty][tx] == INF){
                if(adj[ty][tx] != 1){
                    q.push(make_pair(ty, tx));
                    dist[ty][tx] = dist[y][x] + 1;
                    if(ty == fr && tx == fc) {
                        found = true;
                    }
                }
                else{
                    dist[ty][tx] = -1;
                }
            }
        }
        if(found) break;
    }
}

int main(){
    cin >> N >> M;
    queue<pair<int, int> > wall;
    adj = vector<vector<int> >(N + 1, vector<int>(M + 1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 1) wall.push(make_pair(i, j));
        }
    }
    cin >> H >> W >> sr >> sc >> fr >> fc;
    while(!wall.empty()){
        int y = wall.front().first;
        int x = wall.front().second;
        wall.pop();
        for(int i = y; i > y - H; i--){
            for(int j = x; j > x - W; j--){
                if((1 <= i && i <= N) && (1 <= j && j <= M)){
                    adj[i][j] = 1;
                }
            }
        }
    }
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= M; j++){
    //         cout << adj[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    bfs();
    if(dist[fr][fc] == INF) cout << -1;
    else cout << dist[fr][fc];
}