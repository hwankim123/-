#include<iostream>
using namespace std;

#define MAXN 1024
#define INF -10000000

int N;
int adj[MAXN][MAXN];

int solve(int y1, int x1, int y2, int x2){
    int first = INF, second = INF;
    if(y2 - y1 == 1){
        for(int i = y1; i <= y2; i++){
            for(int j = x1; j <= x2; j++){
                if(first <= adj[i][j]){
                    second = first;
                    first = adj[i][j];
                }
                else if(first > adj[i][j] && second <= adj[i][j]){
                    second = adj[i][j];
                }
            }
        }
        return second;
    }
    int result[4];
    int midY = (y1 + y2) / 2;
    int midX = (x1 + x2) / 2;
    result[0] = solve(y1, x1, midY, midX);
    result[1] = solve(y1, midX + 1, midY, x2);
    result[2] = solve(midY + 1, x1, y2, midX);
    result[3] = solve(midY + 1, midX + 1, y2, x2);
    for(int i = 0; i < 4; i++){
        if(first <= result[i]){
            second = first;
            first = result[i];
        }
        else if(first > result[i] && second <= result[i]){
            second = result[i];
        }
    }
    return second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    cout << solve(0, 0, N - 1, N - 1);
}