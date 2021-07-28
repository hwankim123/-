#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int> > adj;
vector<vector<int> > meltAdj;
vector<vector<bool> > visited;
int numIsland;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int y, int x){
    queue<pair<int, int> >q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = ny + dy[i];
            int tx = nx + dx[i];
            if(ty >= 0 && ty < N && tx >= 0 && tx < M && !visited[ty][tx]){
                if(adj[ty][tx] > 0){
                    visited[ty][tx] = true;
                    q.push(make_pair(ty, tx));
                }
                else{
                    meltAdj[ny][nx]++;
                }
            }
        }
    }
}

void melt(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            adj[i][j] -= meltAdj[i][j];
            if(adj[i][j] < 0) adj[i][j] = 0;
        }
    }
}

void bfs_All(){
    numIsland = 0;
    visited = vector<vector<bool> >(N, vector<bool>(M, false));
    meltAdj = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(adj[i][j] != 0 && !visited[i][j]){
                bfs(i, j);
                numIsland++;
            }
        }
    }
}

int solve(){
    int result = 0;
    while(true){
        bfs_All();
        if(numIsland > 1) return result;
        else if(numIsland == 0) return 0;
        else result++;
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         cout << meltAdj[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        melt();
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         cout << adj[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }
}

int main(){
    cin >> N >> M;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    cout << solve();
}