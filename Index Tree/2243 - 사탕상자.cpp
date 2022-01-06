#include <iostream>
using namespace std;

// index tree의 k 번째 leaf 찾기, index tree update

// 1 << 20 = 2^20 > 1000000 : leaf node가 100만이 넘는 shift 연산 수 20
// leaf node수 만큼 parent node도 있으므로 전체 node 수는 1 << (20+1)
int n, B = 1 << 20;
int candy[1 << 21];

void update(int idx)
{
    while ((idx /= 2) > 0)
    {
        candy[idx] = candy[idx * 2] + candy[idx * 2 + 1];
    }
}

void push(int b, int c)
{
    int idx = b + B - 1;
    candy[idx] += c;
    update(idx);
}

void pull(int c)
{
    int idx = 1;
    while (idx < B)
    {
        if (candy[idx * 2] >= c)
        {
            idx *= 2;
        }
        else
        {
            idx = idx * 2 + 1;
            c -= candy[idx - 1];
        }
    }
    cout << idx - B + 1 << '\n';
    candy[idx] -= 1;
    update(idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            pull(b);
        }
        else if (a == 2)
        {
            cin >> b >> c;
            push(b, c);
        }
    }
}