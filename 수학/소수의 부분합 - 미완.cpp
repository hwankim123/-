#include <iostream>
using namespace std;

const int MAXN = 4000000;
int N;
bool visit[MAXN];
int prime[MAXN];
int primeCnt = 0;

void Eratos()
{
    for (int i = 2; i <= N; i++)
    {
        if (visit[i] == false)
            continue;

        prime[primeCnt++] = i;

        for (int j = i * i; j < N; j *= i)
        {
            if (visit[j] == false)
            {
                visit[j] = false;
            }
        }
    }
    for (int i = 0; i < primeCnt; i++)
    {
        cout << prime[primeCnt] << ' ';
    }
    cout << endl;
}

void solve()
{
    if (N <= 2)
    {
        cout << N - 1;
        return;
    }
    int cnt = 0;
    int lo = 0, hi = 0;
    int sum = 0;

    while (true)
    {
        if (sum < N)
        {
            sum += prime[hi++];
        }
        else
        {
            sum -= prime[lo++];
        }
        if (hi == primeCnt)
        {
            break;
        }
        if (sum == N)
        {
            cnt++;
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