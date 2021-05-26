#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E;
const int MAX_V = 1001;
vector<int> adj[MAX_V];
int start, finish;

int BFS()
{
    vector<int> distance(MAX_V, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        for(vector<int>::iterator it = adj[here].begin(); it != adj[here].end(); it++)
        {
            int there = *it;
            if(distance[there] == -1)
            {
                distance[there] = distance[here] + 1;
                q.push(there);
            }
        }
    }
    return distance[finish];
}

int main()
{
    cin >> start >> finish;
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << BFS();
}