#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int N, M;
const int INF = 100000000;
vector<vector<int> > dis;
vector<vector<int> > adj;
vector<vector<int> > breakC;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    dis[sy][sx] = 1;
    breakC[sy][sx] = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << ' ' << x << ' ' << breakC[y][x] << endl;
        q.pop();
        if(dis[N - 1][M - 1] != -1){
            if(dis[N - 1][M - 1] < dis[y][x]) continue;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < M){
                if(dis[ny][nx] == -1){
                    if(adj[ny][nx] == 0){
                        q.push(make_pair(ny, nx));
                        dis[ny][nx] = dis[y][x] + 1;
                        breakC[ny][nx] = breakC[y][x];
                    }
                    else{
                        if(breakC[y][x] == 0){
                            q.push(make_pair(ny, nx));
                            dis[ny][nx] = dis[y][x] + 1;
                            breakC[ny][nx] = breakC[y][x] + 1;
                        }
                    }
                }
                else if(dis[ny][nx] == dis[y][x] + 1){
                    if(breakC[ny][nx] == 1 && breakC[y][x] == 0){
                        if(adj[ny][nx] == 0){
                            q.push(make_pair(ny, nx));
                            breakC[ny][nx] = breakC[y][x];
                        }
                    }
                }
                else if(dis[ny][nx] < dis[y][x]){
                    if(breakC[ny][nx] == 1 && breakC[y][x] == 0){
                        if(adj[ny][nx] == 0){
                            q.push(make_pair(ny, nx));
                            breakC[ny][nx] = breakC[y][x];
                            dis[ny][nx] = dis[y][x] + 1;
                        }
                    }
                }
            }
        }
    }
    return dis[N - 1][M - 1];
}

int main(){
    cin >> N >> M;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    dis = vector<vector<int> >(N, vector<int>(M, -1));
    breakC = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            adj[i][j] = s[j] - '0';
        }
    }
    cout << bfs(0, 0);
}
