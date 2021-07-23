#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int N, M;
vector<vector<int> >miro;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int bfs()
{
	vector<vector<int> > distance(N, vector<int>(M, -1));
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	distance[0][0] = 1;
	while (!q.empty())
	{
		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ty = hy + dy[i];
			int tx = hx + dx[i];
			if (ty >= 0 && ty < N && tx >= 0 && tx < M)
				if (distance[ty][tx] == -1 && miro[ty][tx] == 1)
				{
					distance[ty][tx] = distance[hy][hx] + 1;
					q.push(make_pair(ty, tx));
				}
		}
	}
	return distance[N - 1][M-1];
}

int main()
{
	cin >> N >> M;
	miro = vector<vector<int> >(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			miro[i][j] = s[j] - '0';
	}
	cout << bfs();
}