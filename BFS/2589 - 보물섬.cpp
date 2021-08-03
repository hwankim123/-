#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int M, N;
vector<vector<char> >adj;
vector<vector<int> >dis;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result;

bool promising(int y, int x) { 
    return y >= 0 && y < M && x >= 0 && x < N && adj[y][x] == 'L' && dis[y][x] == -1;
}

int bfs(int sy, int sx){
    dis = vector<vector<int> >(M, vector<int>(N, -1));
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    dis[sy][sx] = 0;
    int result;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(promising(ty, tx)){
                q.push(make_pair(ty, tx));
                dis[ty][tx] = 1 + dis[y][x];
            }
        }
        result = dis[y][x];
    }
    return result;
}

void solve(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(adj[i][j] == 'L'){
                int temp = bfs(i, j);
                if(temp > result) result = temp;
            }
        }
    }
}

int main(){
    cin >> M >> N;
    adj = vector<vector<char> >(M, vector<char>(N, 'W'));
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            adj[i][j] = s[j];
        }
    }
    solve();
    cout << result;
}