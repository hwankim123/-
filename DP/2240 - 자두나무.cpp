#include<iostream>
using namespace std;

#define MAXT 1001
#define MAXW 31

int T, W;
int tree[MAXT];
int cache[2][MAXT][MAXW];

int max(int y, int x){
    return (y > x) ? y : x;
}

int solve(int here, int loc, int switchCnt){
    if(here == T){
        return 0;
    }
    if(cache[loc][here][switchCnt] != 0){
        return cache[loc][here][switchCnt];
    }
    if(tree[here] == loc){
        cache[loc][here][switchCnt]++;
    }
    if(switchCnt == 0){
        cache[loc][here][switchCnt] += solve(here + 1, loc, switchCnt);
    }
    else{
        cache[loc][here][switchCnt] += max(solve(here + 1, (loc + 1) % 2, switchCnt - 1), solve(here + 1, loc, switchCnt));
    }
    return cache[loc][here][switchCnt];
}

int main(){
    cin >> T >> W;
    for(int i = 0; i < T; i++){
        cin >> tree[i];
        tree[i]--;
    }
    int solve1 = solve(0, 0, W);
    int solve2 = solve(0, 1, W - 1);
    int result = (solve1 > solve2) ? solve1 : solve2; 
    cout << result;
}