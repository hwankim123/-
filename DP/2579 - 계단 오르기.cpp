#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 301

int n;
int arr[MAXN];      // arr[0]은 비어있음
int cache[3][MAXN]; // cache[0][...]은 비어있음. cache[1 and 2][0]은 비어있음.

int solve(int jumpCount, int x)
{
    if (x > n) // Overflow
        return 0;
    if (x == n) // 도착지점
        return arr[x];
    if (jumpCount == 2 && x == n - 1) // 도착지점을 가지 못하는 경우
        return 0;
    if (cache[jumpCount][x] != 0) // caching
        return cache[jumpCount][x];

    int next1, next2;
    if (jumpCount == 1)
    {
        next1 = solve(jumpCount + 1, x + 1);
        next2 = solve(1, x + 2);
        return cache[jumpCount][x] = arr[x] + ((next1 > next2) ? next1 : next2);
    }
    else if (jumpCount == 2)
    {
        return cache[jumpCount][x] = arr[x] + solve(1, x + 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int start1 = solve(1, 1); // 첫번째 칸에서 시작
    int start2 = solve(1, 2); // 두번째 칸에서 시작
    cout << ((start1 > start2) ? start1 : start2);
}