#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 500
#define INF 987654321

int N, M, B;
int adj[MAXN][MAXN];
int heightCnt[257];
int maxN, minN = INF;
int resultT = INF, resultH;

int run(int tempH){
    int result = 0;
    for(int i = minN; i <= maxN; i++){
        if(tempH > i){
            result += (tempH - i) * heightCnt[i];
        }
        else if(tempH < i){
            result += 2 * (i - tempH) * heightCnt[i];
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
            if(maxN < adj[i][j]){
                maxN = adj[i][j];
            }
            if(minN > adj[i][j]){
                minN = adj[i][j];
            }
            heightCnt[adj[i][j]]++;
        }
    }
    for(int i = minN; i <= maxN; i++){
        int sum = 0;
        for(int j = minN; j <= maxN; j++){
            sum += (j - i) * heightCnt[j];
        }
        if(sum + B >= 0){
            int tempH = i;
            int tempT = run(tempH);
            if(resultT > tempT){
                resultT = tempT;
                resultH = tempH;
            } else if(resultT == tempT && resultH < tempH){
                resultT = tempT;
                resultH = tempH;     
            }
        }
    }
    cout << resultT << ' '<< resultH;
}