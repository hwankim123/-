#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int> > adj;
vector<vector<bool> > visited;
int numIsland;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M) return;
    if(visited[y][x]) return;
    if(adj[y][x] <= 0) return;
    visited[y][x] = true;
    int melt = 0;
    for(int i = 0; i < 4; i++){ // 해당 위치의 빙산이 얼마만큼 녹아야하는지를 일단 계산 후 저장.(melt)
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        else if(adj[ny][nx] == 0) melt++;
    } // for문을 분리한 이유 : 반례 2 때문. 이전에 제출했던 코드 참조하면서 리뷰
    for(int i = 0; i < 4; i++){ // DFS 실행
        int ny = y + dy[i];
        int nx = x + dx[i];
        dfs(ny, nx);
    }
    adj[y][x] -= melt; // DFS 실행 완료 후 돌아와서 melt 반영
    // DFS가 완전히 끝난 후에 melt를 반영해야 함. 반례 3 의 이유 때문
    if(adj[y][x] < 0) adj[y][x] = 0;
}

void dfs_All(){
    visited = vector<vector<bool> >(N, vector<bool>(M, false));
    numIsland = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && adj[i][j] != 0){
                dfs(i, j);
                numIsland++;
            }
        }
    }
}

int solve(){
    int result = 0;
    while(true){
        dfs_All();
        if(numIsland > 1) return result;
        else if(numIsland == 0) return 0;
        else result++;
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

/*
 *  DFS로 풀긴 품 : 생각해야 하는 반례
 *  1. Out of Bound
 *  2. 깊이우선으로 들어간 곳이 녹아서 0이 되었는데 다른 인접한 빙산에서 이를 접근해야 하는 경우
 *  3. 깊이우선으로 들어가기 전에 물에 맡닿은 곳이 있어서 그걸 반영하면 오류 발생.
 * 
 *  맘에 안 드는 부분 : dfs()에서 for문을 한번 더 돌리는 점.
 * 
 *  내일(7/27) bfs로 풀면서 시간 차이 확인. 후 리뷰
 */