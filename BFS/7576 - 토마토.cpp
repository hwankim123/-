#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int M, N, countZero = 0;
vector<pair<int, int> > start;
vector<vector<int> > adj(1000, vector<int>(1000, -1));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    int count = 0;
    int result = 0;
    vector<vector<int> >days(M, vector<int>(N, 0));
	queue<pair<int, int> > q;
    //cout <<start.size() << endl; 
    for(int i = 0; i < start.size(); i++){
        q.push(make_pair(start[i].first, start[i].second));
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << ' ' << x << endl;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < M && nx >= 0 && nx < N){
                if(adj[ny][nx] == 0) {
                    adj[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                    days[ny][nx] = days[y][x] + 1;
                    count++;
                }
            }
        }
        result = days[y][x];
    }
    //cout << count <<' '<< countZero << endl;
    if(count != countZero) return -1;
    else return result;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 1){
                start.push_back(make_pair(i, j));
            }
            else if(adj[i][j] == 0){
                countZero++;
            }
        }
    }
    if(countZero == 0) cout << 0;
    else cout << bfs();
}