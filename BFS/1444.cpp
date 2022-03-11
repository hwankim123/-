#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

#define MAXN 1001
#define INF 987654321

int N, M, K;
int adj[MAXN][MAXN];
vector<vector<pair<int, int> > >visited;
int result = INF;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(){
    queue<pair<pair<int, int>, int> >q;
    visited[1][1] = {1, K};
    q.push({{1, 1}, K});
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if((ty >= 1 && ty <= N && tx >= 1 && tx <= M) 
            && (visited[ty][tx].first == INF || (visited[ty][tx].first >= visited[y][x].first + 1 && visited[ty][tx].second < cnt))){
                if(adj[ty][tx] == 1 && cnt >= 1){
                    q.push({{ty, tx}, cnt - 1});
                    visited[ty][tx] = {visited[y][x].first + 1, cnt - 1};
                }
                else if(adj[ty][tx] == 0){
                    q.push({{ty, tx}, cnt});
                    visited[ty][tx] = {visited[y][x].first + 1, cnt};
                }
            }
        }
    }
    if(visited[N][M].first == INF){
        cout << -1;
    } else{
        cout << visited[N][M].first;
    }
}

int main(){
    cin >> N >> M >> K;
    visited = vector<vector<pair<int, int> > >(N + 1, vector<pair<int, int> >(M + 1, {INF, 0}));
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= M; j++){
            adj[i][j] = s[j - 1] - '0';
        }
    }
    bfs();
}