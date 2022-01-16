#include <iostream>
using namespace std;

#define MAXN 17
#define INF 1000000001

int B, N, M;
int arrMin[1 << (MAXN + 1)];
int arrMax[1 << (MAXN + 1)];

int Min(int x, int y)
{
    int lo = x + B - 1, hi = y + B - 1;
    int leftMin = INF, rightMin = INF;
    while (lo <= hi)
    {
        if (lo % 2 == 1)
        {
            leftMin = (leftMin < arrMin[lo]) ? leftMin : arrMin[lo];
        }
        if (hi % 2 == 0)
        {
            rightMin = (rightMin < arrMin[hi]) ? rightMin : arrMin[hi];
        }
        lo = (lo + 1) / 2;
        hi = (hi - 1) / 2;
    }
    return (leftMin < rightMin) ? leftMin : rightMin;
}

int Max(int x, int y)
{
    int lo = x + B - 1, hi = y + B - 1;
    int leftMax = 0, rightMax = 0;
    while (lo <= hi)
    {
        if (lo % 2 == 1)
        {
            leftMax = (leftMax > arrMax[lo]) ? leftMax : arrMax[lo];
        }
        if (hi % 2 == 0)
        {
            rightMax = (rightMax > arrMax[hi]) ? rightMax : arrMax[hi];
        }
        lo = (lo + 1) / 2;
        hi = (hi - 1) / 2;
    }
    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (B = 1; B < N; B <<= 1)
        ;
    for (int i = B; i < B + N; i++)
    {
        cin >> arrMin[i];
        arrMax[i] = arrMin[i];
    }
    for (int i = B + N; i < 1 << (MAXN + 1); i++)
    {
        arrMin[i] = INF;
    }
    for (int i = B - 1; i > 0; i--)
    {
        arrMin[i] = (arrMin[i * 2] < arrMin[i * 2 + 1]) ? arrMin[i * 2] : arrMin[i * 2 + 1];
        arrMax[i] = (arrMax[i * 2] > arrMax[i * 2 + 1]) ? arrMax[i * 2] : arrMax[i * 2 + 1];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << Min(a, b) << ' ' << Max(a, b) << '\n';
    }
}