#include<iostream>
#include<vector>
using namespace std;

int N, K;
vector<vector<long long> > C;

int min(int a, int b){ return (a < b) ? a : b; }

int binomialCoeff(){
    C = vector<vector<long long> >(N + 1, vector<long long>(K + 1, 0));
    
    // bottom up DP
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= min(i, K); j++){
            // base case
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[N][K];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cout << binomialCoeff();
}