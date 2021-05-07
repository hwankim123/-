#include<iostream>
#include<vector>
using namespace std;

// M : 가로 길이(x의 범위) N : 세로 길이(y의 범위)
int testCase, M, N, K, result = 0;
vector<vector<int> > ground(51, vector<int>(51, 0));
vector<vector<bool> > visited(51, vector<bool>(51, false));

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

void dfs(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M) return;
	if (visited[y][x] || ground[y][x] == 0) return;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i]);
}

void dfsAll()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j] && ground[i][j] == 1)
			{
				result++;
				dfs(i, j);
			}
		}
	}
}

int main()
{
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cin >> M >> N >> K;
		int x, y;
		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			ground[y][x] = 1;
		}
		dfsAll();
		cout << result << "\n";
		result = 0;
		ground = vector<vector<int> >(51, vector<int>(51, 0));
		visited = vector<vector<bool> >(51, vector<bool>(51, false));
	}
}