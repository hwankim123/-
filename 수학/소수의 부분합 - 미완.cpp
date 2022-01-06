#include <iostream>
using namespace std;

const int MAXN = 4000000;
int N;
bool visit[MAXN];

void Eratos()
{
    for (int i = 2; i <= N; i++)
    {
        if (visit[i])
            continue;

        for (int j = i * i; j < N; j += i)
        {
            if (!visit[j])
            {
                visit[j] = true;
            }
        }
    }
}

void solve()
{
    if (N <= 2)
    {
        cout << N - 1;
        return;
    }
    int cnt = 0;
    int lo = 0, hi = 0, sum = 0;

    while (hi <= N)
    {
        cout << "lo " << lo << " hi " << hi << " sum " << sum << endl;
        if (sum <= N && !visit[hi])
        {
            hi++;
            continue;
        }
        else if (sum >= N && !visit[lo])
        {
            lo++;
            continue;
        }
        if (!visit[lo])
        {
            sum += hi;
        }
        else
        {
            sum -= lo;
        }
        if (sum == N)
        {
            cnt++;
        }
        else if (sum < N)
        {
            hi++;
        }
        else
        {
            lo++;
        }
    }
    cout << cnt;
}

int main()
{
    cin >> N;
    Eratos();
    solve();
}