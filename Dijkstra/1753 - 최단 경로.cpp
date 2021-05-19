#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1000000000;
const int MAX_V = 20001;
int V, E;
vector<pair<int, int> > adj[MAX_V];
vector<int> result;
vector<int> dijkstra(int src)
{
	vector<int> dist(MAX_V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].second;
			int thereCost = adj[here][i].first;
			if (cost + thereCost < dist[there])
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
	int start;
	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}
	result = dijkstra(start);
	for (int i = 1; i <= V; i++)
	{
		if (result[i] == INF) cout << "INF\n";
		else cout << result[i] << "\n";
	}
}