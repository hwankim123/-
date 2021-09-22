#include<iostream>
#include<cstring>
using namespace std;

int N;
int cache[15];
pair<int, int> adj[15];
int solve(int x){
    if(x >= N) return 0;
    if(cache[x] != -1) return cache[x];
    int temp1 = 0;
    if(x + adj[x].first <= N){
        temp1 = adj[x].second + solve(x + adj[x].first);
    }
    int temp2 = 0;
    if(x + 1 <= N){
        temp2 = solve(x + 1); 
    }
    return cache[x] = (temp1 > temp2) ? temp1 : temp2;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> adj[i].first >> adj[i].second;
    }
    cout << solve(0);
}