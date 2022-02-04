#include<iostream>
using namespace std;

int N;

void find(int cnt, int len){
    int lo = (len - (cnt + 2))/2;
    int hi = lo + cnt + 2;
    if(N <= lo){
        find(cnt - 1, lo);
    }
    else if(N > lo && N <= hi){
        if(N == lo + 1) cout << "m";
        else cout << "o";
    }
    else{
        N -= hi;
        find(cnt - 1, lo);
    }
}

void solve(int cnt, int len){
    if(len >= N){
        find(cnt, len);
        return;
    }
    solve(cnt + 1, len * 2 + 1 + cnt + 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    solve(1, 3);
}