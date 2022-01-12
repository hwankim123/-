#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 51
#define MAXM 14
#define INF 1000000000

int N, M;
pair<int, int> house[MAXN * 2];
pair<int, int> chicken[MAXM];
int houseCnt = 0;
int chickenCnt = 0;
int Top;
pair<int, int> D[MAXM];
int result = INF;

void check(){
    int sum = 0;
    for(int i = 0; i < houseCnt; i++){
        int y = house[i].first;
        int x = house[i].second;
        int min = INF;
        for(int j = 0; j < M; j++){
            int temp = abs(y - D[j].first) + abs(x - D[j].second);
            if(min > temp){
                min = temp;
            }
            if(min == 1){
                break;
            }
        }
        sum += min;
    }
    if(result > sum){
        result = sum;
    }
}

void backtracking(int start){
    if(Top == M){
        check();
        return;
    }
    for(int i = start; i < chickenCnt; i++){
        D[Top++] = chicken[i];
        backtracking(i + 1);
        Top--;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a;
            cin >> a;
            if(a == 1){
                house[houseCnt++] = make_pair(i, j);
            } else if(a == 2){
                chicken[chickenCnt++] = make_pair(i, j);
            }
        }
    }
    Top = 0;
    backtracking(0);
    cout << result;
}