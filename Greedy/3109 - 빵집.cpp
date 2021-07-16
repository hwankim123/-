#include<iostream>
#include<vector>
#include<string>
using namespace std;
int R, C;
vector<vector<char> > adj;
// 순서대로 오른쪽 위, 오른쪽, 오른쪽 아래 방향을 가리키게 하는 배열
int dy[3] = {-1, 0, 1};
// 문제의 답
int result = 0;
void dfs(int y, int x){
	// 격자를 벗어나는 경우
    if(y < 0 || y >= R) return;
	// 'x'에 막혀 파이프를 설치하지 못하는 경우
    if(adj[y][x] == 'x') return;
	// 오른쪽 끝에 도달한 경우
    if(x == C){
        result++;
        return;
    }
	// 아직 파이프라인이 완성되지 않았고, 파이프를 설치할 수 있는 위치임.
    adj[y][x] = 'x';
	// 탐욕법 : 파이프라인을 완성할 수 있는 최초의 경우를 발견하면 result++이 되고, 
	// saveResult와 값이 달라지게 된다.
    int saveResult = result;
    for(int i = 0; i < 3; i++){
        dfs(y + dy[i], x + 1);
		// 이전 경우에서 파이프라인을 완성할 수 있는 최초의 경우를 발견했으면 break로 for문을 빠져나옴
        if(saveResult != result) {
            break;
        }
    }
	// 시간초과 : 잘못된 경로가 있었다면 'x'로 바꿔놓았던 것을 '.'으로 rollback하는 코드.
    //if(saveResult == result) adj[y][x] = '.';
}
void dfs_All(){
	// 파이프라인을 상단에서부터 설치할 수 있는지 확인해나간다.
    for(int i = 0; i < R; i++){
        dfs(i, 0);
    }
}
int main(){
    cin >> R >> C;
    adj = vector<vector<char> >(R, vector<char>(C, '.'));
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            adj[i][j] = s[j];
        }
    }
    dfs_All();
    cout << result;
}