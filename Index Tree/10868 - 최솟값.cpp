#include<iostream>
using namespace std;

#define MAXN 17
#define MAXM 100000
#define INF 9876543210

int N, M, B;
long long adj[1 << (MAXN + 1)];

int cal(int lo, int hi){
    lo = lo + B - 1;
    hi = hi + B - 1;
    long long minNum = INF;
    while(lo <= hi){
        if(lo % 2 == 1){
            minNum = (minNum < adj[lo]) ? minNum : adj[lo];
        }
        if(hi % 2 == 0){
            minNum = (minNum < adj[hi]) ? minNum : adj[hi];
        }
        lo = (lo + 1) / 2; 
        hi = (hi - 1) / 2;
    }
    return minNum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(B = 1; B < N; B <<= 1);
    for(int i = B; i < B + N; i++){
        cin >> adj[i];
    }
    int problem[MAXM][2];
    for(int i = 0; i < M; i++){
        cin >> problem[i][0] >> problem[i][1];
    }
    for(int i = B + N; i < (1 << (MAXN + 1)); i++){
        adj[i] = INF;
    }
    for(int i = B - 1; i > 0; i--){
        adj[i] = (adj[i * 2] < adj[i * 2 + 1]) ? adj[i * 2] : adj[i * 2 + 1];
    }

    for(int i = 0; i < M; i++){
        cout << cal(problem[i][0], problem[i][1]) << '\n';
    }
}