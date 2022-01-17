#include<iostream>
using namespace std;

#define MAXN 201
#define MAXM 1001

int N, M;
int set[MAXN];

int Find(int here){
    if(set[here] == here){
        return here;
    }
    return set[here] = Find(set[here]);
}

void Union(int child, int parent){
    if(child == parent) return;
    set[Find(child)] = Find(parent);
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        set[i] = i;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a; cin >> a;
            if(a == 1){
                Union(j, i);
            }
        }
    }
    int save = -1;
    for(int i = 0; i < M; i++){
        int path; cin >> path;
        if(save == -1) save = Find(path);
        else{
            if(Find(path) != save){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

}