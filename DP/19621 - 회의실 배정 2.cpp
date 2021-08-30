#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> adj;
int N;
int cache[25];

int solve(int here){
    if(here < 0 || here >= N) return 0;
    if(cache[here] != -1) return cache[here];
    else{
        int notHere = solve(here + 1);
        int includeHere = adj[here] + solve(here + 2);
        cache[here] = (notHere > includeHere) ? notHere : includeHere;
    }
    return cache[here];
}

int main(){
    cin >> N;
	memset(cache, -1, sizeof(cache));
    adj = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[i] = c;
    }
    cout << solve(0);
}