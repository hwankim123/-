#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, Q;
const int MAX_N = 5001, INF = 1000000000;
vector<pair<int, int> > adj[MAX_N];
vector<int> video;
vector<int> K;
vector<int> result;
vector<bool> visited;
int sum;

void search(int here, int minK){
    // cout << "here : " << here << endl;
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].second;
        if(!visited[there]){
            if(minK > adj[here][i].first){
                result[there] = adj[here][i].first;
            }
            else{
                result[there] = minK;
            }
            // cout << "result[" << there << "] set : " << result[there] << endl;
            search(adj[here][i].second, result[there]);
        }
    }
}

void solve(){
    for(int i = 0; i < Q; i++){
        result = vector<int>(N+1, -INF);
        visited = vector<bool>(N+1, false);
        search(video[i], INF);
        sum = 0;
        for(int j = 1; j <= N; j++){
            if(result[j] >= K[i]){
                sum++;
            }
        }
        cout << sum << endl;
    }
}

int main(){
    cin >> N >> Q;
    for(int i = 0; i < N - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    for(int i = 0; i < Q; i++){
        int k, v;
        cin >> k >> v;
        video.push_back(v);
        K.push_back(k);
    }
    solve();
}
