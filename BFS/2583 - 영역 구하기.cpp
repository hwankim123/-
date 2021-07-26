#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int M, N, K;
vector<vector<bool> >adj(100, vector<bool>(100, false));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> area;
int result = 0;
void bfs(int y, int x){
    adj[y][x] = true;
    area.push_back(1);
    queue<pair<int, int> >q;
    q.push(make_pair(y, x));
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = ny + dy[i];
            int tx = nx + dx[i];
            if(ty >= 0 && ty < M && tx >= 0 && tx < N && !adj[ty][tx]){
                adj[ty][tx] = true;
                q.push(make_pair(ty, tx));
                area[result]++;
            }
        }
    }
}

void bfs_All(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!adj[i][j]){
                bfs(i, j);
                result++;
            }
        }
    }
}

int main(){
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        for(int j = ay; j < by; j++){
            for(int k = ax; k < bx; k++){
                adj[j][k] = true;
            }
        }
    }
    bfs_All();
    cout << result << endl;
    sort(area.begin(), area.end());
    for(int i = 0; i < result; i++){
        cout << area[i] << ' ';
    }
}