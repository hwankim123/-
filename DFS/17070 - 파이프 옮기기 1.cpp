#include<iostream>
#include<cstring>
using namespace std;

int N;
int tile[17][17];
int cache[17][17][3];
const int moveL = 0;
const int diagonal = 1;
const int down = 2;

int solve(int y, int x, int state)
{
	switch (state)
	{
	case 0:
		if (tile[y][x] == 1) return 0;
		if (cache[y][x][moveL] != -1) return cache[y][x][moveL];
		break;
	case 1:
		if (tile[y][x] == 1 || tile[y-1][x] == 1 || tile[y][x-1] == 1) return 0;
		if (cache[y][x][diagonal] != -1) return cache[y][x][diagonal];
		break;
	case 2:
		if (tile[y][x] == 1) return 0;
		if (cache[y][x][down] != -1) return cache[y][x][down];
		break;
	}
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;
	if (tile[y][x] == 1) return 0;
	switch (state)
	{
	case 0: cache[y][x][state] = solve(y, x + 1, moveL) + solve(y + 1, x + 1, diagonal);
		break;
	case 1: cache[y][x][state] = solve(y, x + 1, moveL) + solve(y + 1, x + 1, diagonal) + solve(y + 1, x, down);
		break;
	case 2: cache[y][x][state] = solve(y + 1, x + 1, diagonal) + solve(y + 1, x, down);
		break;
	}
	return cache[y][x][state];
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> tile[i][j];
	cout << solve(0, 1, moveL);
	
}