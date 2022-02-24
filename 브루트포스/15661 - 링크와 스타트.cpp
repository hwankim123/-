#include<iostream>
#include<vector>
using namespace std;

#define MAXN 21

int N;
int adj[MAXN][MAXN];
int result = 987654321;

void cal(vector<int> team1){
    int j = 0;
    vector<int> team2;
    int sum_team1 = 0;
    int sum_team2 = 0;
    for(int i = 0; i < N; i++){
        if(j < team1.size() && i == team1[j]){
            j++;
            continue;
        }
        team2.push_back(i);
    }
    for(int i = 0; i < team1.size() - 1; i++){
        for(int j = i + 1; j < team1.size(); j++){
            sum_team1 += adj[team1[i]][team1[j]] + adj[team1[j]][team1[i]];
        }
    }
    for(int i = 0; i < team2.size() - 1; i++){
        for(int j = i + 1; j < team2.size(); j++){
            sum_team2 += adj[team2[i]][team2[j]] + adj[team2[j]][team2[i]];
        }
    }
    if(result > abs(sum_team1 - sum_team2)){
        result = abs(sum_team1 - sum_team2);
    }
}

void combination(vector<int> team1, int here, int k){
    if(team1.size() == k){
        cal(team1);
        return;
    }
    team1.push_back(here);
    combination(team1, here + 1, k);
    if(N - here - 1 > k - team1.size()){
        team1.pop_back();
        combination(team1, here + 1, k);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 2; i <= N / 2; i++){
        vector<int> team;
        combination(team, 0, i);
    }
    cout << result;
}