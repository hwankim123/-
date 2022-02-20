#include<iostream>
#include<stack>
using namespace std;

#define MAXL 1002

char s1[MAXL];
char s2[MAXL];
int cache[MAXL][MAXL];
int s1Len, s2Len;
pair<int, int> parent[MAXL][MAXL];
stack<char> result;

bool allSame(int i, int j){
    return (cache[i - 1][j - 1] == cache[i][j - 1]) && (cache[i - 1][j - 1] == cache[i - 1][j]);
}

int max(int y, int x){
    return (y > x) ? y : x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    int i = 0, j = 0;
    while(true){
        if(s1[i] == '\0'){
            s1Len = i;
            break;
        }
        j = 0;
        while(true){
            if(s2[j] == '\0'){
                s2Len = j;
                break;
            }
            if(s1[i] == s2[j] && allSame(i + 1, j + 1)){
                cache[i + 1][j + 1] = cache[i][j] + 1;
                parent[i + 1][j + 1] = {i, j};
            }
            else{
                if(cache[i][j + 1] > cache[i + 1][j]){
                    cache[i + 1][j + 1] = cache[i][j + 1];
                    parent[i + 1][j + 1] = {i, j + 1};
                }else{
                    cache[i + 1][j + 1] = cache[i + 1][j];
                    parent[i + 1][j + 1] = {i + 1, j};
                }
            }
            j++;
        }
        i++;
    }
    cout << cache[s1Len][s2Len];
    int y = s1Len, x = s2Len;
    while(cache[y][x] != 0){
        if(s1[y] == s2[x]){
            result.push(s1[y]);
        }
        int newY = parent[y][x].first;
        int newX = parent[y][x].second;
        y = newY;
        x = newX;
    }
    result.push(s1[y]);
    if(result.top() != '\0'){
        cout << endl;
        while(!result.empty()){
            cout << result.top();
            result.pop();
        }
    }
}