#include<iostream>
#include<string.h>
using namespace std;

#define MAXN 41

int T, N;
int cache[MAXN][2];
void fib(int n){
    if(n <= 1){
        return;
    }
    if(cache[n][0] != 0 || cache[n][1] != 0){
        return;
    }
    fib(n - 2);
    fib(n - 1);
    cache[n][0] = cache[n - 2][0] + cache[n - 1][0];
    cache[n][1] = cache[n - 2][1] + cache[n - 1][1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++){
        memset(cache, 0, sizeof(cache));
        cache[1][1] = 1;
        cache[0][0] = 1;
        cin >> N;
        fib(N);
        cout << cache[N][0] << ' ' << cache[N][1] << '\n';
    }
}