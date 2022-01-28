#include<iostream>
#include<vector>
using namespace std;

#define MAXN 5
#define INF 10000001

long long N, B;
int result[MAXN][MAXN];
vector<vector<int> >cache[INF];

void solve(long long b){
    if(b == 0) return;
    if(b < INF && cache[b].size() != 0){
        return;
    }
    if(b < INF){
        cache[b] = vector<vector<int> >(N, vector<int>(N, 0));
        solve(b / 2);
        if(b % 2 == 0){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    for(int k = 0; k < N; k++){
                        cache[b][i][j] += cache[b / 2][i][k] * cache[b / 2][k][j];
                    }
                    cache[b][i][j] %= 1000;
                }
            }
        }
        else{
            solve(b / 2 + 1);
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    for(int k = 0; k < N; k++){
                        cache[b][i][j] += cache[b / 2][i][k] * cache[b / 2 + 1][k][j];
                    }
                    cache[b][i][j] %= 1000;
                }
            }
        }
    }
    else{
        
    }
}

int main(){
    cin >> N >> B;
    cache[1] = vector<vector<int> >(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cache[1][i][j];
        }
    }

    cache[2] = vector<vector<int> >(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cache[2][i][j] += cache[1][i][k] * cache[1][k][j];
            }
        }
    }
    long long count = B;
    while(count > 0){
        if(cache[count].size() == 0){
            solve(count);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                result[i][j] = (result[i][j] + cache[count][i][j]) % 1000;
            }
        }
        count--;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}