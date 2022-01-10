#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 501

int N;
vector<int> adj[MAXN];
queue<int> q;
int indegree[MAXN];

int answer[MAXN];
int time[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        time[i] = x;
        while(true){
            cin >> x;
            if(x == -1) break;
            adj[x].push_back(i);
            indegree[i]++;
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
            answer[i] = time[i];
        }
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            answer[there] = max(answer[there], time[there] + answer[here]);
            if(--indegree[there] == 0){
                q.push(there);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << answer[i] << ' ';
    }
}