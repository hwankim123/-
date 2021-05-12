#include<iostream>
#include<vector>
#include<list>
using namespace std;

int N, M;
// 인접 리스트로 구현한 이유 : 
vector<list<int> > adj;
vector<bool> visited;

// 모든 노드들이 서로 연결되어있지는 않은 위상정렬을 생각.
// A 가 B보다 앞에 와야하는데 보통의 위상정렬은 reverse해서 출력해야 하므로
// 애초에 방향성을 A -> B로 하지 않고 B -> A로 설정함

void dfs(int here)
{
	visited[here] = true;
	for (list<int>::iterator it = adj[here].begin(); it != adj[here].end(); it++)
	{
		int there = *it;
		if (!visited[there])
			dfs(there);
	}
	cout << here << ' ';
}

void dfsAll()
{
	visited = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
		if (!visited[i] && adj[i].size() > 1)
			dfs(i);
}

int main()
{
	cin >> N >> M;
	adj = vector<list<int> >(N + 1);
	for (int i = 0; i <= N; i++)
		adj[i].push_back(i);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	dfsAll();
	// 키를 비교한 적이 없는 학생을 출력하지 않음 ... DFS가 끝난 후 아직 방문하지 않은 학생들을 출력
	for (int i = 1; i <= N; i++)
		if (!visited[i]) cout << i << ' ';
}