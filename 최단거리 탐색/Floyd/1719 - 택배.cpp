#include<iostream>
using namespace std;

#define MAXN 201
#define INF 987654321

int n, m;
int adj[MAXN][MAXN];
int result[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k) continue;
                if(adj[j][i] == INF || adj[i][k] == INF) continue;
                if(adj[j][k] > adj[j][i] + adj[i][k]){
                    if(j == 1 && k == 6) cout << "Asd " << i << endl;
                    if(j == 6 && k == 1) cout << "qwrfqwrfwq " << i << endl;
                    if(result[j][k] == 0 || result[j][k] != i){
                        result[j][k] = i;
                    }
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << "- ";
            } else if(result[i][j] == 0){
                cout << j << ' ';
            } else{
                cout << result[i][j] << ' ';
            }
        }
        cout << endl;
    }
}