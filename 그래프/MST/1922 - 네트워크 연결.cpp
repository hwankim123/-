#include<iostream>
#include<queue>
using namespace std;

#define MAXN 1001

// mst - 크루스칼 알고리즘 사용

int n, m;
int set[MAXN];
priority_queue<pair<int, pair<int, int> > > pq;
int cnt = 1, sum;

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
        pq.push(make_pair(-c, make_pair(a, b)));
    }
    while(cnt <= n - 1){
        pair<int, pair<int, int> > data = pq.top();
        int cost = -data.first;
        int parent = data.second.first;
        int child = data.second.second;
        pq.pop();
        if(Find(child) != Find(parent)){
            Union(child, parent);
            sum += cost;
            cnt++;
        }
    }
    cout << sum;
}