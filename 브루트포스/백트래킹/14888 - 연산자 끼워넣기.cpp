#include<iostream>
#include<vector>
using namespace std;

int N;
int adj[11];
vector<int> opeNum(4, 0); // 덧 뻴 곱 나
int big = -1000000000, small = 1000000000;

void start(int x, int result, vector<int> ope){
    if(x == N - 1){
        if(result > big) big = result;
        if(result < small) small = result;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(ope[i] > 0){
            ope[i]--;
            switch(i){
                case 0:
                    start(x + 1, result + adj[x + 1], ope);
                    break;
                case 1:
                    start(x + 1, result - adj[x + 1], ope);
                    break;
                case 2:
                    start(x + 1, result * adj[x + 1], ope);
                    break;
                case 3:
                    start(x + 1, result / adj[x + 1], ope);
                    break;
            }
            ope[i]++;
        }
    }
}

void solve(){
    vector<int> temp(4, 0);
    for(int i = 0; i < 4; i++){
        temp[i] = opeNum[i];
    }
    start(0, adj[0], temp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> adj[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> opeNum[i];
    }
    solve();
    cout << big << endl << small;
}