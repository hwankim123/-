#include<iostream>
using namespace std;

#define MAXN 21

int N;
int L[MAXN];
int J[MAXN];

int solve(int here, int sum, int hp){
    if(here == N) return 0;
    int a = 0;
    if(hp - L[here] > 0){
        a = J[here] + solve(here + 1, J[here] + sum, hp - L[here]);
    }
    int b = solve(here + 1, sum, hp);
    return (a > b) ? a : b;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }
    for(int i = 0; i < N; i++){
        cin >> J[i];
    }
    cout << solve(0, 0, 100);
}
