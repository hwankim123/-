#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 100000000;
int N;
vector<vector<int> >adj;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool promising(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < N;
}

vector<vector<int> > dijkstra(){
    vector<vector<int> >dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int> > >pq;
    dist[0][0] = adj[0][0];
    pq.push(make_pair(-dist[0][0], make_pair(0, 0)));
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
                int thereCost = adj[ty][tx];
                if(dist[ty][tx] > thereCost + cost){
                    dist[ty][tx] = cost + thereCost;
                    pq.push(make_pair(-dist[ty][tx], make_pair(ty, tx)));
                }
            }

        }
    }
    return dist;
}

int main(){
    int count = 1;
    while(true){
        cin >> N;
        if(N == 0) break;
        adj = vector<vector<int> >(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> adj[i][j];
            }
        }
        vector<vector<int> > result = dijkstra();
        cout << "Problem " << count << ": " << result[N-1][N-1] << endl;
        count++;
    }
}