#include<iostream>
#include<string>
using namespace std;

#define MAXN 64

int N;
int adj[MAXN][MAXN];

string solve(int y1, int x1, int y2, int x2){
    if(y1 == y2 && x1 == x2){
        if(adj[y1][x1] == 1) return "1";
        else if(adj[y1][x1] == 0) return "0";
    }
    int midY = (y1 + y2) / 2;
    int midX = (x1 + x2) / 2;
    string temp[4];
    temp[0] = solve(y1, x1, midY, midX);
    temp[1] = solve(y1, midX + 1, midY, x2);
    temp[2] = solve(midY + 1, x1, y2, midX);
    temp[3] = solve(midY + 1, midX + 1, y2, x2);
    string start = temp[0];
    for(int i = 1; i < 4; i++){
        if(start.size() > 1 || temp[i].size() > 1 || start != temp[i]){
            string s = "(";
            for(int j = 0; j < 4; j++){
                s += temp[j];
            }
            s += ")";
            return s;
        }
    }
    return start;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            adj[i][j] = s[j] - '0';
        }
    }
    cout << solve(0, 0, N - 1, N - 1);
}