#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<vector<int> > adj;
vector<vector<bool> > visited;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

// 땅으로 인식하고 돌아다닐 공기 : air, 이때 값이 바뀔 공기는 air == 2일때 0 / air == 0일때 2
bool make_Air(int sy, int sx, int air) { // inner만 0으로 남기고 나머지를 다 2로 바꿈
    bool result = false;
    visited = vector<vector<bool> >(N, vector<bool>(M, false));
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    if (air == 0) {
        adj[sy][sx] = 2;
    }
    visited[sy][sx] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];
            if (ty >= 0 && ty < N && tx >= 0 && tx < M && !visited[ty][tx]) {
                if (adj[ty][tx] == 0) {
                    adj[ty][tx] = 2;
                }
                if (adj[ty][tx] != 1) {
                    visited[ty][tx] = true;
                    q.push(make_pair(ty, tx));
                }
                else result = true; // 아직 녹일 치즈가 남아있다면 return true
            }
        }
    }
    return result; // 녹일 치즈가 없어서 초기값 그대로 false이면 return false
}

void bfs(int sy, int sx) {
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        int count = 0;
        for (int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];
            if (ty >= 0 && ty < N && tx >= 0 && tx < M) {
                if (!visited[ty][tx] && adj[ty][tx] == 2) {
                    count++;
                }
                if (count == 2) {
                    adj[y][x] = 2;
                }
                if (!visited[ty][tx] && adj[ty][tx] == 1) {
                    visited[ty][tx] = true;
                    q.push(make_pair(ty, tx));
                }
            }
        }
    }
}

void bfs_All() {
    visited = vector<vector<bool> >(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && adj[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
}

void solve() {
    make_Air(0, 0, 0);
    int count = 0;
    bool result = true;
    while (result) {
        bfs_All();
        result = make_Air(0, 0, 2);
        count++;
    }
    cout << count;
}

int main() {
    cin >> N >> M;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }
    solve();
}