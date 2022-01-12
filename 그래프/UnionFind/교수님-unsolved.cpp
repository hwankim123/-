#include <iostream>
using namespace std;

#define MAXN 100001

int set[MAXN];
int weight[MAXN];
// find하면서 weight를 update
// 경로 압축으로 인해 모든 자손들은 부모보다 몇 가벼운지가 저장됨.
// 자손끼리 비교할 때 |(부모 - 자손1) - (부모 - 자손2)| == |자손1 - 자손2|
// Find 결과가 다를 때 비교 불가

int Find(int here)
{
    if (set[here] == here)
    {
        return here;
    }
    return set[here] = Find(set[here]);
}

void Union(int child, int parent)
{
    if (child == parent)
    {
        return;
    }
    set[Find(child)] = Find(parent);
}

int main()
{
    int n, m;
    while (true)
    {
        cin >> n >> m;
        if (!n && !m)
            break;

        for (int i = 0; i <= n; i++)
        {
            set[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            char symbol;
            int a, b, w;
            cin >> symbol >> a >> b;
            if (symbol == '!')
            {
                cin >> w;
                Union(a, b);
            }
            else if (symbol == '?')
            {
            }
        }
    }
}