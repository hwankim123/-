#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int N, M;
list<pair<int, int> > adj[101][101];
vector<vector<bool> > visited;
vector<vector<bool> > turnedOn;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int bfs(int sy, int sx){
    int count = 0;
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    visited = vector<vector<bool> >(N + 1, vector<bool>(N + 1, false));
    visited[sy][sx] = true;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(list<pair<int, int> >::iterator it = adj[y][x].begin(); it != adj[y][x].end();){
            int ty = (*it).first;
            int tx = (*it).second;
            if(!turnedOn[ty][tx]){
                turnedOn[ty][tx] = true;
                it = adj[ty][tx].erase(it);
                count++;
            } else{
                it++;
            }
        }
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(ty >= 1 && ty <= N && tx >= 1 && tx <= N && !visited[ty][tx] && turnedOn[ty][tx]){
                visited[ty][tx] = true;
                q.push(make_pair(ty, tx));
            }
        }
    }
    return count;
}

void solve(){
    turnedOn = vector<vector<bool> >(N + 1, vector<bool>(N + 1, false));
    turnedOn[1][1] = true;
    int sum = 1;
    while(true){
    int temp = bfs(1, 1);
        if(temp != 0){
            sum += temp;
        }
        else{
            cout << sum;
            return;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a][b].push_back(make_pair(c, d));
    }
    solve();
}