#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int Y, X, N;
vector<vector<char> > adj;
vector<int> ope;
vector<vector<int> >visited; // 초기 : -1
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
void print();

void down(int c, int h){
    for(int i = Y - 1 - h; i >= 0; i--){
        for(int j = X - 1; j >= 0; j--){
            if(visited[i][j] == c){
                adj[i][j] = '.';
                adj[i + h][j] = 'x';
            }
        }
    }
}

pair<int, int> bfs(int sy, int sx, int count){
    int under = sy;
    int height = 1110;
    queue<pair<int, int> >q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = count;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        //cout << 'y' << y << 'x' << x << endl;
        if(y < Y - 1 && adj[y + 1][x] == '.'){ // 공중에 떠있을 때. // under != -1 && under != Y - 1 && 
            int h = 0;
            bool same = true;
            while((y + 1 + h) <= Y - 1 && adj[y + 1 + h][x] == '.'){
                //cout << "y + 1 + h " << y + 1 + h << ' ' << x << adj[y + 1 + h][x] << endl;
                h++;
            }
            //cout << "h : " << h << endl;
            if(y + h == Y - 1){
                if(height > h) height = h;
            }
            else if(y + 1 + h <= Y - 1 && visited[y + 1 + h][x] != count){
                if(height > h) height = h;
            }
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(ty >= 0 && ty < Y && tx >= 0 && tx < X && visited[ty][tx] == -1 && adj[ty][tx] == 'x'){
                visited[ty][tx] = count;
                q.push(make_pair(ty, tx));
                //if(under < ty) under = ty;
            }
        }
    }
    //cout << "under : " << under << endl;
    //cout << "end" << endl;
    if(under == Y - 1) return make_pair(count, -1);
    else return make_pair(count, height);
}

pair<int, int> bfsAll(){
    int height = -1;
    int count = 0;
    for(int i = Y - 1; i >= 0; i--){
        for(int j = X - 1; j >= 0; j--){
            if(visited[i][j] == -1 && adj[i][j] == 'x'){
                pair<int, int> result = bfs(i, j, count);
                if(result.second != -1) return result;
                count++;
            }
        }
    }
    return make_pair(count, -1);
}

void solve(){
    for(int i = 0; i < N; i++){
        visited = vector<vector<int> >(Y, vector<int>(X, -1));
        int y = Y - ope[i];
        int x;
        bool flag = false;
        if(i % 2 == 0){
            x = 0;
            while(x < X){
                if(adj[y][x] == 'x') {
                    adj[y][x] = '.';
                    flag = true;
                    break;
                }
                x++;
            }
        }
        else{
            x = X - 1;
            while(x >= 0){
                if(adj[y][x] == 'x') {
                    adj[y][x] = '.';
                    flag = true;
                    break;
                }
                x--;
            }
        }
        //cout << "after hit" << endl;
        //print();
        if(flag == true){
            pair<int, int> result = bfsAll();
            //cout << "\nresult : " << result.first << ' ' << result.second << endl;
            if(result.second != -1){
                down(result.first, result.second);
            }
            //print();
        }
    }
}

int main(){
    cin >> Y >> X;
    adj = vector<vector<char> >(Y, vector<char>(X, '.'));
    for(int i = 0; i < Y; i++){
        char s[101];
        cin >> s;
        for(int j = 0; j < X; j++){
            adj[i][j] = s[j];
        }
    }
    cin >> N;
    ope = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> ope[i];
    }
    solve();
    print();
}

void print(){
    for(int i = 0; i < Y; i++){
        for(int j = 0; j < X; j++){
            cout << adj[i][j];
        }
        cout << endl;
    }
}