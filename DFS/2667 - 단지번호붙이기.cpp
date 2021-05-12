#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, num = 0;
vector<int> houseNum;
vector<vector<int> > house;
vector<vector<bool> > visited;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	if ((y < 0 || x < 0) || (y >= N || x >= N)) return;
	if (visited[y][x] || house[y][x] == 0) return;
	visited[y][x] = true;
	houseNum[houseNum.size() - 1]++;
	for (int i = 0; i < 4; i++)
	{
		int newY = dy[i] + y;
		int newX = dx[i] + x;
		dfs(newY, newX);
	}
}

void dfsAll()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j] && house[i][j] == 1)
			{
				houseNum.push_back(0);
				dfs(i, j);
				num++;
			}
}

int main()
{
	cin >> N;
	house = vector<vector<int> >(N, vector<int>(N, 0));
	visited = vector<vector<bool> >(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			house[i][j] = s[j] - '0';
	}
	dfsAll();
	sort(houseNum.begin(), houseNum.end());

	cout << num << endl;
	for (int i = 0; i < num; i++) cout << houseNum[i] << endl;
}