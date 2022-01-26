#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 500000

int N, M;
int card[MAXN];
int num[MAXN];

int target;
bool solve(int lo, int hi){
    if(lo > hi) return false;

    int mid = (lo + hi) / 2;
    if(target > card[mid]){
        lo = mid + 1;
        return solve(lo, hi);
    } else if(target < card[mid]){
        hi = mid - 1;
        return solve(lo, hi);
    } else{
        return true;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> card[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num[i];
    }
    sort(card, card + N);
    for(int i = 0; i < M; i++){
        target = num[i];
        if(solve(0, N - 1)){
            cout << 1 << ' ';
        } else{
            cout << 0 << ' ';
        }
    }
}