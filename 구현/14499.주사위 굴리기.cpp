#include<iostream>
#include<vector>
using namespace std;

int N, M, x, y, K;
vector<vector<int> > adj;
// diceDir : 문제의 전개도 상의 숫자 배치로 시작. 
// for문을 돌리면서 해당 index(1~6. 원래 전개도 기준의 위, 아래, 오른, 왼, 앞, 뒤) 위치에 초기 전개도의 어느 숫자가 들어가있는지
int diceDir[7] = {0, 1, 2, 3, 4, 5, 6}; 
// diceNum : 초기 전개도의 숫자에 적힌 값 저장
int diceNum[7];
// diceMove : 1 2 3 4 방향으로 구를 때 바꿔줘야 하는 전개도 상의 숫자들의 ary 및 순서.
int diceMove[5][4] = {
    {0, 0, 0, 0},
    {1, 3, 6, 4}, // e
    {1, 4, 6, 3}, // w
    {1, 2, 6, 5}, // n
    {1, 5, 6, 2} // s
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> x >> y >> K;
    adj = vector<vector<int> >(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int dir;
        cin >> dir;
        x += dx[dir];
        y += dy[dir];
        if(x == -1 || x == N || y == -1 || y == M){
            x -= dx[dir];
            y -= dy[dir];
            continue;
        }
        int save = diceDir[diceMove[dir][0]];
        int temp;
        for(int j = 0; j < 4; j++){
            temp = save;
            save = diceDir[diceMove[dir][(j + 1) % 4]];
            diceDir[diceMove[dir][(j + 1) % 4]] = temp;
        }
        if(adj[x][y] != 0){
            diceNum[diceDir[6]] = adj[x][y];
            adj[x][y] = 0;
        }
        else{
            adj[x][y] = diceNum[diceDir[6]];
        }
        cout << diceNum[diceDir[1]] << '\n';
    }
}