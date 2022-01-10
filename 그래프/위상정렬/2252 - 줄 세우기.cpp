#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 32001

// 위상 정렬 기본

int N, M;

// 위상 정렬에 필요한 세 가지 자료구조
queue<int> q; // 출발 노드를 저장하는 queue
vector<int> adj[MAXN]; // 비순환, 유향 그래프
int indegree[MAXN]; // 자신에게로 향하는 노드의 개수

vector<int> answer;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // a가 b의 선행조건이다. a --> b
        indegree[b]++;
    }

    // queue init
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // 위상 정렬
    while(!q.empty()){
        int here = q.front();
        q.pop();
        answer.push_back(here);
        // adj[here][i]를 중복으로 search하지 않는 이유 : 비순환 그래프이기 때문
        // 비순환 그래프이기 때문에 한번 찾은 adj[here][i]는 search할때 다시 조회하지 않는다.
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            if(--indegree[there] == 0){
                q.push(there);
            }
        }
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
}