#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, result; // result : 결과 출력
vector<vector<int> > adj;
vector<vector<int> > visited;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int bfs(int sy, int sx){
    int count = 0; // 안전 영역의 크기
    bool foundVirus = false; // 바이러스를 찾았는지의 여부
    if(adj[sy][sx] != 2) count++; // 출발지점이 바이러스가 아니므로 안전 영역의 크기++
    else foundVirus = true; // 출발지점이 바이러스일 경우 true

    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(ty >= 0 && ty < N && tx >= 0 && tx < M && visited[ty][tx] == 0){
                if(adj[ty][tx] != 1){
                    visited[ty][tx] = 1;
                    q.push(make_pair(ty, tx));
                    count++; // BFS를 진행하며 방문 할 때마다 안전 영역의 크기++
                    if(adj[ty][tx] == 2) foundVirus = true; // 만약 바이러스를 찾았다면 true
                }
            }
        }
    }
    if(foundVirus) return 0; // 해당 영역의 BFS 결과 바이러스를 찾았다면 안전 영역이 아니므로 0 return
    else return count; // 안전 영역일 경우에 누적한 안전 영역의 크기(count) return
}

void bfsAll(){
    visited = vector<vector<int> >(N, vector<int>(M, 0));
    int sum = 0; // 각각의 벽을 세운 경우의 총 안전 영역의 크기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0 && adj[i][j] != 1){
                sum += bfs(i, j);
            }
        }
    }
    if(result < sum) { // 기존 안전 영역의 최댓값보다 클 경우 갱신
        result = sum;
    }
}

void solve(){
    // 벽을 세우는 for문. 벽을 3개 세워야 하므로 3중 for문
    for(int i = 0; i < N * M; i++){
        for(int j = i + 1; j < N * M; j++){ // 이전 수와 겹치지 않도록 j = i + 1
            for(int k = j + 1; k < N * M; k++){ // 이전 수와 겹치지 않도록 k = j + 1
                // 0 ~ N x M 까지의 수 중 오름차순으로 3개를 선택. 선택한 수들은 i, j, k
                int wy[3] = {i / M, j / M, k / M}; // 각각의 벽의 y 좌표 : M을 i, j, k로 나눈 몫
                int wx[3] = {i % M, j % M, k % M}; // 각각의 벽의 x 좌표 : M을 i, j, k로 나눈 나머지
                bool found = true; // 이미 벽이 설치되었는지의 여부
                for(int c = 0; c < 3; c++){
                    if(adj[wy[c]][wx[c]] != 0){
                        found = false; // 벽이 이미 설치되었으므로 false
                        break;
                    }
                }
                if(found){ // 세 곳에 벽이 모두 없었다면
                    for(int c = 0; c < 3; c++){
                        adj[wy[c]][wx[c]] = 1; // 세 곳에 벽을 설치
                    }
                    bfsAll(); // BFS
                    for(int c = 0; c < 3; c++){
                        adj[wy[c]][wx[c]] = 0; // 모든 경우를 따져야 하므로 벽을 제거
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    solve();
    cout << result;
}
