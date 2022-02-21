#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1000001
#define INF 1000000000

int N;
pair<int, int> line[MAXN];

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int lo, hi;
        cin >> lo >> hi;
        line[i] = {lo, hi};
    }
    sort(line, line + N, compare);
    int length = 0;
    int lo = -INF, hi = -INF;
    for(int i = 0; i < N; i++){
        //cout << "lo : " << lo << " hi : " << hi << endl;
        if(hi < line[i].first){ // 선이 끊어졌을 때
            length += hi - lo;
            lo = line[i].first;
            hi = line[i].second;
        }
        if(hi < line[i].second){ // 선이 이어지고, 더 길어질 때(위의 if문을 통과했기 때문에 선이 이어진 것임)
            hi = line[i].second;
        }

    }
    cout << length + hi - lo;
}