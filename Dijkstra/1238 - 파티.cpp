#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Dijkstra를 모든 정점에 대해 수행하여 해결. Floyd 공부 후 다시 풀고 시간 비교

int N, M, X;
const int MAX_N = 1001;
const int INF = 1000000000;
vector<pair<int, int> > adj[MAX_N];
vector<int> result;
priority_queue<int> print;

vector<int> Dijkstra(int src)
{
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, src));
	vector<int> dist(MAX_N, INF);
	dist[src] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		int s = adj[here].size();
		for (int i = 0; i < s; i++)
		{
			int there = adj[here][i].second;
			int thereCost = adj[here][i].first;
			if (dist[there] > cost + thereCost)
			{
				dist[there] = cost + thereCost;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}
	return dist;
}

int main()
{
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}

	result = Dijkstra(X);
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		vector<int> temp = Dijkstra(i);
		result[i] += temp[X];
		print.push(result[i]);
	}
	cout << print.top();
}