#include<iostream>
#include<vector>
using namespace std;

#define MAXN 5

long long N, B;
vector<vector<int> > mat;
vector<vector<int> > mat2;
vector<vector<int> > result;
vector<vector<int> > temp;

vector<vector<int> >cal(vector<vector<int> > m1, vector<vector<int> > m2){
    vector<vector<int> >temp(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                temp[i][j] += m1[i][k] * m2[k][j];
            }
            temp[i][j] %= 1000;
        }
    }
    return temp;
}

void solve(long long b, vector<vector<int> >& cur){
    if(b == 1){
        cur = mat;
        return;
    }
    if(b == 2){
        cur = mat2;
        return;
    }
    vector<vector<int> >temp1(N, vector<int>(N, 0));
    vector<vector<int> >temp2(N, vector<int>(N, 0));
    solve(b / 2, temp1);
    if(b % 2 == 0){
        cur = cal(temp1, temp1);
    }
    else{
        temp2 = cal(temp1, mat);
        cur = cal(temp1, temp2);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> B;
    mat = vector<vector<int> >(N, vector<int>(N, 0));
    mat2 = vector<vector<int> >(N, vector<int>(N, 0));
    vector<bool> checked(B, false);
    cout << checked.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    // mat2 = cal(mat, mat);
    // for(int i = 1; i <= B; i++){
    //     if(i == 1) result = mat;
    //     else if(i == 2){
    //         for(int i = 0; i < N; i++){
    //             for(int j = 0; j < N; j++){
    //                 result[i][j] += mat2[i][j];
    //             }
    //         }
    //     }
    //     else{
    //         temp = vector<vector<int> >(N, vector<int>(N, 0));
    //         solve(i, temp);
    //         for(int i = 0; i < N; i++){
    //             for(int j = 0; j < N; j++){
    //                 result[i][j] = (result[i][j] + temp[i][j]) % 1000;
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << result[i][j] % 1000 << ' ';
    //     }
    //     cout << '\n';
    // }
}