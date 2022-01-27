#include<iostream>
using namespace std;

#define MAXN 101
#define INF 987654321

int n, m, r;
int adj[MAXN][MAXN];
int item[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> item[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        adj[a][b] = l;
        adj[b][a] = l;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k) continue;
                if(adj[j][i] == INF || adj[i][k] == INF) continue;
                if(adj[j][k] > adj[j][i] + adj[i][k]){
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }

    int result = -INF;
    for(int i = 1; i <= n; i++){
        int sum = item[i];
        for(int j = 1; j <= n; j++){
            if(adj[i][j] == INF) continue;
            if(adj[i][j] <= m){
                sum += item[j];
            }
        }
        if(result < sum) result = sum;
    }
    cout << result;
}