#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int l = 6, r = 2;
int adj[5][8];
int K;
pair<int, int> ope[100];

void ShiftRight(int n){
    int save = adj[n][7];
    int temp = save;
    for(int i = 7; i >= 0; i--){
        if(temp != adj[n][i - 1]){
            adj[n][i] = adj[n][i - 1];
        }
        temp = adj[n][i - 1];
    }
    adj[n][0] = save;
}

void ShiftLeft(int n){
    int save = adj[n][0];
    int temp = save;
    for(int i = 0; i < 8; i++){
        if(temp != adj[n][i + 1]){
            adj[n][i] = adj[n][i + 1];
        }
        temp = adj[n][i+1];
    }
    adj[n][7] = save;
}

void turn(int num, int dir, const string lr){
    if(lr == "right"){
        if(dir == 1){
            if(num + 1 < 5 && adj[num][r] != adj[num + 1][l]){
                turn(num + 1, -1, "right");
                ShiftLeft(num + 1);
            }
        }
        else{
            if(num + 1 < 5 && adj[num][r] != adj[num + 1][l]){
                turn(num + 1, 1, "right");
                ShiftRight(num + 1);
            }
        }
    }
    else{
        if(dir == 1){
            if(num - 1 >= 0 && adj[num][l] != adj[num - 1][r]){
                turn(num - 1, -1, "left");
                ShiftLeft(num - 1);
            }
        }
        else{
            if(num - 1 >= 0 && adj[num][l] != adj[num - 1][r]){
                turn(num - 1, 1, "left");
                ShiftRight(num - 1);
            }
        }
    }
}

void solve(){
    for(int i = 0; i < K; i++){
        int num = ope[i].first;
        int dir = ope[i].second;
        turn(num, dir, "right");
        turn(num, dir, "left");
        if(dir == 1){
            ShiftRight(num);
        }
        else{
            ShiftLeft(num);
        }
        // for(int i = 1; i < 5; i++){
        //     for(int j = 0; j < 8; j++){
        //         cout << adj[i][j];
        //     }
        //     cout << endl;
        // }
    }
}

int main(){
    for(int i = 1; i <= 4; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            adj[i][j] = s[j] - '0';
        }
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        ope[i] = make_pair(a, b);
    }
    solve();
    int mul = 1;
    int sum = 0;
    for(int i = 1; i < 5; i++){
        if(adj[i][0] == 1){
            sum += mul;
        }
        mul *= 2;
    }
    cout << sum << endl;
}