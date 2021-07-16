#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int> >adj(500, vector<int>(500, 0));
vector<vector<int> >cash(500, vector<int>(500, -1));

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int dfs(int y, int x){
    if(cash[y][x] != -1) return cash[y][x];
    int max = 0;
    for(int i = 0; i < 4; i++){
        int newY = y + dy[i];
        int newX = x + dx[i];
        int temp = 0;
        // 메모리 초과로 인해 기저 사례를 재귀함수 호출 부분으로 뺌.
        if(newY >= 0 && newY < n && newX >= 0 && newX < n && adj[y][x] < adj[newY][newX])
            temp = dfs(newY, newX);
        max = (max > temp) ? max : temp;
    }
    cash[y][x] = max + 1;
    return cash[y][x];
}

int result = 0;
void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            if(cash[i][j] != -1) temp = cash[i][j];
            else temp = dfs(i, j);
            result = (result > temp) ? result : temp;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    solve();
    cout << result << endl;
}