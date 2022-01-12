#include<iostream>
using namespace std;

#define MAXN 10

int N, M;
int Top;
int D[MAXN];

void printD(){
    for(int i = 0; i < M; i++){
        cout << D[i] << ' ';
    }
    cout << '\n';
}

void backtracking(int start){
    if(Top == M){
        printD();
        return;
    }

    for(int i = start; i <= N; i++){
        if(N-i+1 < M-Top) break; // 가지치기. 수열의 개수가 적으면 오히려 느려진대
        D[Top++] = i;
        backtracking(i + 1);
        Top--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "combination\n";
    N = 5;
    M = 3;
    Top = 0;
    backtracking(1);
}