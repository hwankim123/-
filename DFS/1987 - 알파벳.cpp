#include<iostream>
#include<vector>
using namespace std;

/*

단순 DFS : 채점 결과 시간 거의 1초
백트래킹 & 분기 한정법 써서 다시 풀고 블로그 리뷰

*/

vector<vector<int>> map = vector<vector<int>>(20, vector<int>(20, 0));
vector<bool> visited = vector<bool>(100, false);
int R, C;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int y, int x){
    if(y < 0 || y >= R || x < 0 || x >= C)
        return 0;
    if(visited[map[y][x]])
        return 0;
    visited[map[y][x]] = true;

    // weight : 인접한 칸들 중 가장 멀리 갈 수 있는 칸의 갯수.
    int weight = 0;
    for(int i = 0; i < 4; i++){
        int temp = dfs(y + dy[i], x + dx[i]);
        if(weight < temp) weight = temp; 
    }
    visited[map[y][x]] = false;

    // 자기 자신(1)과 다음 칸을 탐색한 결과(weight)를 더함.
    return 1 + weight;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            map[i][j] = s[j] - 'A';
        }
    }
    cout << dfs(0, 0);
}