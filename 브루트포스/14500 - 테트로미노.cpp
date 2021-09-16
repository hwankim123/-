#include<iostream>
using namespace std;

int N, M;
int adj[500][500];

bool promising(int y, int x, int k){
    switch(k){
        case 0:// ㅁ
            return y + 1 < N && x + 1 < M;
        case 1:// l
            return y + 3 < N;
        case 2: // ----
            return x + 3 < M;
        case 3: // ,--
        case 4: // `--
        case 5: // ㅡ,
        case 6: // ㄱ_
        case 7: // ㅜ
            return y + 1 < N && x + 2 < M;
        case 8: // l_
        case 9: // `l
        case 10: // l`
        case 11: // ㄴ,
        case 12: // ㅏ
            return y + 2 < N && x + 1 < M;
        case 13: // .l
        case 14: // ㅓ
        case 15: // ,-`
            return y + 2 < N && x - 1 >= 0;
        case 16: // ㅗ
        case 17: // .l`
            return y + 1 < N && x + 1 < M && x - 1 >= 0;
        case 18: // ㅡㅡ`
            return y + 1 < N && x - 2 >= 0;
    }
}

int cal(int i, int j, int k){
    switch(k){
        case 0:// ㅁ
            return adj[i][j] + adj[i + 1][j] + adj[i][j + 1] + adj[i + 1][j + 1];
        case 1:// l
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i + 3][j];
        case 2: // ----
            return adj[i][j] + adj[i][j + 1] + adj[i][j + 2] + adj[i][j + 3];
        case 3: // ,--
            return adj[i][j] + adj[i + 1][j] + adj[i][j + 1] + adj[i][j + 2];
        case 4: // `--
            return adj[i][j] + adj[i + 1][j] + adj[i + 1][j + 1] + adj[i + 1][j + 2];
        case 5: // ㅡ,
            return adj[i][j] + adj[i][j + 1] + adj[i][j + 2] + adj[i + 1][j + 2];
        case 6: // ㄱ_
            return adj[i][j] + adj[i][j + 1] + adj[i + 1][j + 1] + adj[i + 1][j + 2];
        case 7: // ㅜ
            return adj[i][j] + adj[i][j + 1] + adj[i + 1][j + 1] + adj[i][j + 2];
        case 8: // l_
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i + 2][j + 1];
        case 9: // `l
            return adj[i][j] + adj[i][j + 1] + adj[i + 1][j + 1] + adj[i + 2][j + 1];
        case 10: // l`
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i][j + 1];
        case 11: // ㄴ,
            return adj[i][j] + adj[i + 1][j] + adj[i + 1][j + 1] + adj[i + 2][j + 1];
        case 12: // ㅏ
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i + 1][j + 1];
        case 13: // .l
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i + 2][j - 1];
        case 14: // ㅓ
            return adj[i][j] + adj[i + 1][j] + adj[i + 2][j] + adj[i + 1][j - 1];
        case 15: // ,-`
            return adj[i][j] + adj[i + 1][j] + adj[i + 1][j - 1] + adj[i + 2][j - 1];
        case 16: // ㅗ
            return adj[i][j] + adj[i + 1][j] + adj[i + 1][j - 1] + adj[i + 1][j + 1];
        case 17: // .l`
            return adj[i][j] + adj[i][j + 1] + adj[i + 1][j] + adj[i + 1][j - 1];
        case 18: // ㅡㅡ`
            return adj[i][j] + adj[i + 1][j] + adj[i + 1][j - 1] + adj[i + 1][j - 2];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    int result = 4;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 19; k++){
                if(promising(i, j, k)){
                    int temp = cal(i, j, k);
                    if(result < temp){
                        result = temp;
                    }
                }
            }
        }
    }
    cout << result;
}