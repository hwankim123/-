#include<iostream>
using namespace std;

const int maxNum = 2187;
int N;
int paper[maxNum][maxNum];
int result[3] = { 0, 0, 0 };

void solve(int size, int y, int x)
{
	if (size == 1)
	{
		result[paper[y][x] + 1]++;
		return;
	}
	bool diff = false;
	bool stop = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (paper[y + i][x + j] != paper[y + size - (i + 1)][x + size - (j + 1)] || paper[y][x] != paper[y + i][x + j])
			{
				diff = true;
				break;
			}
			if (y + i == y + size - (i + 1) && x + j == x + size - (j + 1))
			{
				if (paper[y][x] != paper[y + i][x + j])
				{
					diff = true;
					break;
				}
				else
				{
					stop = true;
					break;
				}
			}
		}
		if (diff || stop) break;
	}
	if (!diff)
	{
		result[paper[y][x] + 1]++;
		return;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				solve(size / 3, y + (size / 3) * i, x + (size / 3) * j);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	solve(N, 0, 0);
	cout << result[0] << endl;
	cout << result[1] << endl;
	cout << result[2] << endl;
}