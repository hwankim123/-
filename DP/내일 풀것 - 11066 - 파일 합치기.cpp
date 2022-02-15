#include<iostream>
#include<memory.h>
using namespace std;

#define MAXK 500

int T, K;
int cache[MAXK][MAXK];
int sum[MAXK][MAXK];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        memset(cache, 0, sizeof(cache));
        memset(sum, 0, sizeof(sum));
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> sum[j][j];
        }
        for(int i = 1; i < K; i++){
            int j = 0;
            int k = i;
            while(k < K){
                sum[j][k] = sum[j + 1][k] + sum[j][k - 1] - sum[j + 1][k - 1];
                j++; k++;
            }
        }
        for(int i = 1; i < K; i++){
            int j = 0;
            int k = i;
            while(k < K){
                cache[j][k] = 987654321;
                for(int l = 0; l < k - j; l++){
                    int temp = cache[j][j + l] + cache[j + l + 1][k] + sum[j][k];
                    if(temp < cache[j][k]){
                        cache[j][k] = temp;
                    }
                }
                j++; k++;
            }
        }
        cout << cache[0][K - 1] << '\n';
    }
}