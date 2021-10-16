#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 100000;
int N;
int adj[MAX][3];
int cache[2][3];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0; i < 3; i++) cache[1][i] = adj[N - 1][i];
    int i = N - 1;
    while(i != 0){
        for(int j = 0; j < 3; j++){
            int result = 0;
            for(int k = 0; k < 3; k++){
                if(j == 0 && k == 2) continue;
                if(j == 2 && k == 0) continue;
                if(result < adj[i - 1][j] + cache[1][k]) {
                    result = adj[i - 1][j] + cache[1][k];
                }
            }
            cache[0][j] = result;
        }
        for(int j = 0; j < 3; j++){
            cache[1][j] = cache[0][j];
        }
        i--;
    }
    int result = 0;
    for(int i = 0; i < 3; i++){
        if(result < cache[1][i]) result = cache[1][i];
    }
    cout << result << ' ';
    
    for(int i = 0; i < 3; i++) cache[1][i] = adj[N - 1][i];
    i = N - 1;
    while(i != 0){
        for(int j = 0; j < 3; j++){
            int result = 100000000;
            for(int k = 0; k < 3; k++){
                if(j == 0 && k == 2) continue;
                if(j == 2 && k == 0) continue;
                if(result > adj[i - 1][j] + cache[1][k]) {
                    result = adj[i - 1][j] + cache[1][k];
                }
            }
            cache[0][j] = result;
        }
        for(int j = 0; j < 3; j++){
            cache[1][j] = cache[0][j];
        }
        i--;
    }
    result = 100000000;
    for(int i = 0; i < 3; i++){
        if(result > cache[1][i]) result = cache[1][i];
    }
    cout << result;

}