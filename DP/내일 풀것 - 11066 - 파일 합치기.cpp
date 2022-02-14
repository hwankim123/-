#include<iostream>
#include<memory.h>
using namespace std;

#define MAXK 500

int T, K;
int cache[501][501];
// 두 파일의 합을 저장하는 배열과, 총 계산 결과값을 저장하는 배열을 따로 둬서 다시 풀기
// 피라미드 형식으로 cache를 이용하는 것은 맞음

int solve(int lo, int hi){
    if(cache[lo][hi] != 0){
        return cache[lo][hi];
    }
    if(lo + 1 == hi){
        return cache[lo][hi] = cache[lo][lo] + cache[hi][hi];
    }
    cache[lo][hi] = 987654321;
    for(int i = lo; i < hi; i++){
        int a = solve(lo, i);
        if(i != lo) a *= 2;
        int b = solve(i + 1, hi);
        if(i + 1 != hi) b *= 2;
        int temp = a + b;
        if(cache[lo][hi] > temp){
            cache[lo][hi] = temp;
        }
    }
    return cache[lo][hi];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++){
        memset(cache, 0, sizeof(cache));
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> cache[i][i];
        }
        cout << solve(0, K - 1) << '\n';
    }
}