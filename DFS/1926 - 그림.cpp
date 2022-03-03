#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int> >adj;
vector<vector<bool> >visited;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int dfs(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= m || visited[y][x] || adj[y][x] == 0){
        return 0;
    }
    visited[y][x] = true;
    int sum = 1;
    for(int i = 0; i < 4; i++){
        sum += dfs(y + dy[i], x + dx[i]);
    }
    return sum;
}

void dfs_all(){
    int cnt = 0;
    int maxNum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && adj[i][j] == 1){
                int temp = dfs(i, j);
                cnt++;
                if(maxNum < temp) maxNum = temp;
            }
        }
    }
    cout << cnt << endl << maxNum;
}

int main(){
    cin >> n >> m;
    adj = vector<vector<int> >(n, vector<int>(m, 0));
    visited = vector<vector<bool> >(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            adj[i][j] = x;
        }
    }
    dfs_all();
}