#include<iostream>
using namespace std;

#define MAXN 510

int n;
int arr[MAXN][MAXN];
int cache[MAXN][MAXN];

int max(int a, int b){
    return (a > b) ? a : b;
}

void solve(int y){
    if(y > n){
        return;
    }
    if(y == 1){
        cache[y][y] = arr[y][y];
    }
    else{
        for(int i = 1; i <= y; i++){
            cache[y][i] = max(cache[y - 1][i - 1], cache[y - 1][i]) + arr[y][i];
        }
    }
    solve(y + 1);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    solve(1);
    int result = 0;
    for(int i = 1; i <= n; i++){
        if(cache[n][i] > result) result = cache[n][i];
    }
    cout << result;

}