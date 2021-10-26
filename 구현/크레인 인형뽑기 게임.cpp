#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, j = 0, l = moves.size();
    stack<int> bag;
    while (j < l) {
        int here = moves[j] - 1;
        for (int i = 0; i < board[0].size(); i++) {
            if (board[i][here] != 0) {
                if (!bag.empty() && bag.top() == board[i][here]) {
                    bag.pop();
                    answer += 2;
                }
                else {
                    bag.push(board[i][here]);
                }
                board[i][here] = 0;
                break;
            }
        }
        j++;
    }
    return answer;
}

int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > board = vector<vector<int> >(n, vector<int>(n, 0));
    vector<int> moves;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        moves.push_back(a);
    }
    cout << solution(board, moves);
}