#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int INF = 1000000000, MAX_N = 50;
vector<vector<int> >adj;
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool promising(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < N;
}

vector<vector<int> > dijkstra(){
    vector<vector<int> > dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    dist[0][0] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if(dist[y][x] < cost) continue;

        for(int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(promising(ty, tx)){
                int thereCost = cost;
                if(adj[ty][tx] == '0'){
                    thereCost++;
                }
                if(thereCost < dist[ty][tx]){
                    pq.push(make_pair(-thereCost, make_pair(ty, tx)));
                    dist[ty][tx] = thereCost;
                }
            }
        }
    }
    return dist;
}

int main(){
    cin >> N;
    adj = vector<vector<int> >(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            adj[i][j] = s[j];
        }
    }
    vector<vector<int> > result = dijkstra();
    cout << result[N - 1][N - 1];
}