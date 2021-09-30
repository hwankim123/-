#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int adj[21][21];
int result = 1000000000;

void comb(vector<int> team1, int num){
    if(num == N/2){
        int sum1 = 0;
        int sum2 = 0;
        vector<bool> team2(N+1, true);
        for(int i = 0; i < team1.size(); i++){
            team2[team1[i]] = false;
            for(int j = 0; j < team1.size(); j++){
                sum1 += adj[team1[i]][team1[j]];
            }
        }
        for(int i = 1; i <= N; i++){
            if(team2[i]){
                for(int j = 1; j <= N; j++){
                    if(team2[j]){
                        sum2 += adj[i][j];
                    }
                }
            }
        }
        if(result > abs(sum1 - sum2)) result = abs(sum1 - sum2);   
        return;
    }
    ++num;
    for(int i = team1[team1.size() - 1] + 1; i <= N/2 + num; i++){
        team1.push_back(i);
        comb(team1, num);
        team1.pop_back();
    }
}

void solve(){
    // 1은 무조건 포함. (2 ~ N) 중에 N/2 - 1 개를 선택
    vector<int> team1(1, 1);
    for(int i = 2; i <= N/2 + 2; i++){
        team1.push_back(i);
        comb(team1, 2);
        team1.pop_back();
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> adj[i][j];
        }
    }
    solve();
    cout << result;
}