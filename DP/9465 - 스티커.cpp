#include<iostream>
#include<memory.h>
using namespace std;

#define MAXN 100000

int T, N;
int card[2][MAXN];
int sum[2][MAXN];
int cache[2][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        memset(sum, 0, sizeof(sum));
        memset(cache, 0, sizeof(cache));
        cin >> N;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                cin >> card[i][j];
                if(j == 0){
                    sum[i][j] = card[i][j];
                }
            }
        }
        for(int j = 1; j < N; j++){
            for(int i = 0; i < 2; i++){
                sum[i][j] = sum[(i + 1) % 2][j - 1] + card[i][j];

            }
        }
        cache[0][0] = sum[0][0];
        cache[1][0] = sum[1][0];
        if(N == 1){
            int result = (cache[0][0] > cache[1][0]) ? cache[0][0] : cache[1][0];
            cout << result << '\n';
            continue;
        }
        for(int j = 1; j < N; j++){
            for(int i = 0; i < 2; i++){
                int tempMax = (sum[(i + 1) % 2][j - 1] > cache[(i + 1) % 2][j - 1]) ? sum[(i + 1) % 2][j - 1] : cache[(i + 1) % 2][j - 1];
                cache[i][j] = tempMax + card[i][j];
                if(i == 0){
                    if(j >= 2){
                        tempMax = (cache[0][j - 2] > cache[1][j - 2]) ? cache[0][j - 2] : cache[1][j - 2]; 
                        cache[i][j] = (tempMax + card[i][j] > cache[i][j]) ? tempMax + card[i][j] : cache[i][j]; 
                    }
                }   else{
                    if(j >= 2){
                        tempMax = (cache[0][j - 2] > cache[1][j - 2]) ? cache[0][j - 2] : cache[1][j - 2]; 
                        cache[i][j] = (tempMax + card[i][j] > cache[i][j]) ? tempMax + card[i][j] : cache[i][j]; 
                    }
                }
            }
        }
        int result = (cache[0][N - 1] > cache[1][N - 1]) ? cache[0][N - 1] : cache[1][N - 1];
        cout << result << '\n';
    }
}