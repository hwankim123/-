#include<iostream>
#include<vector>
using namespace std;

// 이분 탐색 활용 문제
// 이분 탐색 문제의 본질 : 결정 문제 --> FFF...FT...TTT 를 만족하는 문제 조건인경우
// false에서 true로 바뀌는 경계를 결정하는 문제


int N, M;
vector<int> tree;

int main(){
    cin >> N >> M;
    tree = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }
    int lo = 0, hi = 1e9;
    int mid;
    while(lo + 1< hi){
        mid = (lo + hi) / 2;
        //cout << endl << "mid: " << mid << ' ' << " lo: " << lo << " hi: " << hi << ' ';
        long long sum = 0;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid){
                sum += tree[i] - mid;
            }
        }
        //cout << "sum : " << sum;
        if(sum >= M){
            lo = mid;
        } else if(sum < M){
            hi = mid;
        }
    }
    cout << lo; // 왜 mid에서 lo로 바꿔야 정답이 나오는지(아마 while의 조건과 if(sum >= M) 조건이 바뀌어서 그런듯)
    // 강사님 왈 : TTTT .. FFFF 이런 식으로 진행되는 스타일의 문제는 lo가 답이 되고,
    // FFFF .. TTTT 이런 식으로 진행되는 스타일의 문제는 hi가 답이란다.
}