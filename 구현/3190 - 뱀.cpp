#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int apple = 3;
const int body = 1, head = 2;
int N, K, L;
int adj[101][101];
pair<int, char> task[100];
queue<pair<int, int> > snake;

int main(){
    memset(adj, 0, sizeof(adj));
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = apple;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int a;
        char b;
        cin >> a >> b;
        task[i] = make_pair(a, b);
    }
    int now = 0; // 현재 task
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int dir = 0;
    int y = 1, x = 1;
    snake.push(make_pair(y, x));
    adj[y][x] = head; // init(뱀이 출발점에 위치)
    for(int i = 1; i <= 10000; i++){

        adj[y][x] = body;
        y += dy[dir];
        x += dx[dir];
        if(y == 0 || y == N + 1 || x == 0 || x == N + 1){
            cout << i;
            break;
        }
        if(adj[y][x] == 0){
            pair<int, int> p = snake.front();
            snake.pop();
            adj[p.first][p.second] = 0;
        }
        else if(adj[y][x] == body){
            pair<int, int> p = snake.front();
            snake.pop();
            cout << i;
            break;
        }
        adj[y][x] = head; // 머리 이동
        snake.push(make_pair(y, x));
        if(i == task[now].first){
            if(task[now].second == 'L'){
                dir--;
                if(dir == -1) dir = 3;
            }
            else{
                dir = (dir + 1) % 4;
            }
            now++;
        }
    }
}