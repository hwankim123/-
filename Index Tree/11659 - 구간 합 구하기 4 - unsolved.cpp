#include <iostream>
using namespace std;

// unsolved
// 왜 틀리지......? --> MAXL 16이 아니라 17((1<<17) > 100,000)

#define MAXL 16
int n, m, B;
int arr[1 << (MAXL + 1)];

int cal(int a, int b)
{
    int lo = a + B - 1, hi = b + B - 1;
    int sum = 0;
    while (lo <= hi)
    {
        if (lo % 2 == 1)
        {
            sum += arr[lo];
        }
        if (hi % 2 == 0)
        {
            sum += arr[hi];
        }
        lo = (lo + 1) / 2;
        hi = (hi - 1) / 2;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (B = 1; B < n; B <<= 1)
        ;
    for (int i = B; i < B + n; i++)
    {
        cin >> arr[i];
    }
    for (int i = B - 1; i > 0; i--)
    {
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << cal(a, b) << '\n';
    }
}