#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int> > map;
const int INF = 1000000;
const int virus = -1;
const int wall = -2;
const int ground = -3;
int dy[4] = { 0, -1, 0 ,1 };
int dx[4] = { -1, 0, 1 ,0 };

void bfs(vector<vector<int> >& distance, int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	distance[y][x] = 0;
	while (!q.empty())
	{
		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ty = hy + dy[i];
			int tx = hx + dx[i];
			if (ty >= 0 && ty < N && tx >= 0 && tx < N && (map[ty][tx] == ground || map[ty][tx] == virus))
			{
				if (distance[ty][tx] == -1 || distance[hy][hx] + 1 < distance[ty][tx])
				{
					distance[ty][tx] = distance[hy][hx] + 1;
					q.push(make_pair(ty, tx));
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	map = vector<vector<int> >(N, vector<int>(N, 0));
	vector<pair<int, int> > vPoint;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			map[i][j] -= 3;
			if (map[i][j] == virus) vPoint.push_back(make_pair(i, j));
		}

	int len = vPoint.size();
	vector<bool> v(len - M, false);
	v.insert(v.end(), M, true);
	vector<vector<int> > distance(N, vector<int>(N, -1));
	int result = INF;
	do
	{
		vector<pair<int, int> > temp;
		for (int k = 0; k < len; k++)
			if (v[k]) temp.push_back(vPoint[k]);
		for (int i = 0; i < temp.size(); i++)
			bfs(distance, temp[i].first, temp[i].second);

		int time = 0;
		bool error = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != wall && distance[i][j] == -1)
				{
					error = true;
					break;
				}
				if (time < distance[i][j]) time = distance[i][j];
			}
			if (error) break;
		}
		if (!error && result > time) result = time;
		distance = vector<vector<int> >(N, vector<int>(N, -1));

	} while (next_permutation(v.begin(), v.end()));

	if (result == INF) cout << -1 << endl;
	else cout << result << endl;

}