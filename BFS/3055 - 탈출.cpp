#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int R, C;
vector<vector<char> >adj;
vector<vector<int> >dist;
int start_sy, start_sx, endY, endX;
vector<int>start_wy;
vector<int>start_wx;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool promising(int y, int x){
    return y < R && y >= 0 && x < C && x >= 0;
}

void bfs(){
    dist[start_sy][start_sx] = 0;
    queue<pair<pair<int, int>, char> >q;
    for(int i = 0; i < start_wy.size(); i++){
        q.push(make_pair(make_pair(start_wy[i], start_wx[i]), '*'));
    }
    q.push(make_pair(make_pair(start_sy, start_sx), 'S'));
    bool endFlag = false;
    while(!q.empty()){
        if(endFlag) break;
        int y = q.front().first.first;
        int x = q.front().first.second;
        char type = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(promising(ty, tx)){
                if(type == '*'){
                    if(adj[ty][tx] == '.'){
                        q.push(make_pair(make_pair(ty, tx), '*'));
                        adj[ty][tx] = '*';
                    }
                }
                else if(type == 'S'){
                    if(adj[ty][tx] == '.' && dist[ty][tx] == -1){
                        dist[ty][tx] = 1 + dist[y][x];
                        q.push(make_pair(make_pair(ty, tx), 'S'));
                    }
                    else if(adj[ty][tx] == 'D'){
                        dist[ty][tx] = 1 + dist[y][x];
                        endFlag = true;
                    }
                    //cout << "ty : " << ty << " tx : " << tx << "    " << dist[ty][tx] << endl;
                }
            }
        }
    }
}

int main(){
    cin >> R >> C;
    adj = vector<vector<char> >(R, vector<char>(C, '.'));
    dist = vector<vector<int> >(R, vector<int>(C, -1));
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < C; j++){
            adj[i][j] = s[j];
            if(adj[i][j] == 'S'){
                adj[i][j] = '.';
                start_sy = i;
                start_sx = j;
            }
            else if(adj[i][j] == '*'){
                start_wy.push_back(i);
                start_wx.push_back(j);
            }
            else if(adj[i][j] == 'D'){
                endY = i;
                endX = j;
            }
        }
    }
    bfs();
    if(dist[endY][endX] == -1) cout << "KAKTUS";
    else cout << dist[endY][endX];
}
