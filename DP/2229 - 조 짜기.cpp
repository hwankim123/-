#include<iostream>
using namespace std;

#define MAXN 1001
#define INF 987654321
int N;
int grade[MAXN];
int cache[MAXN][MAXN];
int minG[MAXN][MAXN];
int maxG[MAXN][MAXN];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> grade[i];
    }
    for(int i = 0; i < N; i++){
        if(grade[i] > grade[i + 1]){
            minG[i][i + 1] = grade[i + 1];
            maxG[i][i + 1] = grade[i];
        }
        else{
            minG[i][i + 1] = grade[i];
            maxG[i][i + 1] = grade[i + 1];
        }
        cache[i][i + 1] = abs(grade[i] - grade[i + 1]);
    }
    int j = 2;
    while(true){
        if(j == N) break;
        int k = j; 
        int i = 0; 
        while(true){
            if(k == N) break;
            minG[i][k] = (minG[i][k - 1] < minG[i + 1][k]) ? minG[i][k - 1] : minG[i + 1][k];
            maxG[i][k] = (maxG[i][k - 1] > maxG[i + 1][k]) ? maxG[i][k - 1] : maxG[i + 1][k];
            i++;
            k++;
        }
        j++;
    }
    j = 2;
    while(true){
        if(j == N) break;
        int k = j; 
        int i = 0; 
        while(true){
            if(k == N) break;
            int maxGrade = maxG[i][k] - minG[i][k];
            for(int l = 0; l < k - i; l++){
                int y = i + l + 1;
                int x = i + l;
                maxGrade = ( maxGrade > cache[i][x] + cache[y][k]) ?  maxGrade : cache[i][x] + cache[y][k];
            }
            cache[i][k] = maxGrade;
            i++;
            k++;
        }
        j++;
    }
    cout << cache[0][N - 1];
}