#include<iostream>
using namespace std;

#define MAXN 1000001

// 0 ~ n (이 코드는 n포함!!!) 까지를 i로 초기화
// Find를 경로 압축과 함께 진행
// Union(a, b)시 a의 최상단 노드의 부모를 b의 최상단 노드로 설정

int n, m;
int set[MAXN];

int Find(int here){
    if(set[here] == here){
        return here;
    }
    return set[here] = Find(set[here]);
}

void Union(int child, int parent){
    if(child == parent){
        return;
    }
    set[Find(child)] = Find(parent);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        set[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            Union(b, c);
        } else if(a == 1){
            if(b == c){
                cout << "YES\n";
            } else{
                if(Find(b) == Find(c)){
                    cout << "YES\n";
                } else{
                    cout << "NO\n";
                }
            }
        }
    }
}