#include<iostream>
using namespace std;

int N, M;
int arr[1025][1025];
int cache[1025][1025];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1] + arr[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << cache[x2][y2] - cache[x2][y1 - 1] - cache[x1 - 1][y2] + cache[x1 - 1][y1 - 1] << '\n';
    }
}