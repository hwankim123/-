#include<iostream>
using namespace std;

// Visit flag를 이용한 순열 코드

#define MAXN 10

int N, M;
int Top;
bool Visit[MAXN];
int D[MAXN];

void printD(){
    for(int i = 0; i < M; i++){
        cout << D[i] << ' ';
    }
    cout << endl;
}

void backtracking(){
    if(Top == M){
        printD();
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!Visit[i]){
            Visit[i] = true;
            D[Top++] = i;
            backtracking();
            Top--;
            Visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "permutation\n";
    N = 5;
    M = 3;
    Top = 0;
    backtracking();
    cout << "\n";
}