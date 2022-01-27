#include <iostream>
using namespace std;

#define MAX_HEIGHT 3072
#define MAX_WIDTH 6144

int N;
int width, height;

char adj[MAX_HEIGHT][MAX_WIDTH];

void solve(int y, int x, int n)
{ // y 와 x는 부분문제 삼각형의 밑변의 중점의 좌표 [y][x]
    int width = 5 * (n / 3) + (n / 3) - 1;
    if (n == 3)
    {
        adj[y - 2][x] = '*';
        adj[y - 1][x - 1] = '*';
        adj[y - 1][x + 1] = '*';
        for (int i = x - width / 2; i <= x + width / 2; i++)
        {
            adj[y][i] = '*';
        }
        return;
    }
    n /= 2;
    solve(y - n, x, n);
    solve(y, (2 * x - width / 2) / 2, n);
    solve(y, (2 * x + width / 2 + 1) / 2, n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    width = 5 * (N / 3) + (N / 3) - 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < width; j++)
        {
            adj[i][j] = ' ';
        }
        adj[i][width] = '\0';
    }

    solve(N - 1, width / 2, N);

    for (int i = 0; i < N; i++)
    {
        cout << adj[i] << '\n';
    }
}