#include <iostream>
using namespace std;

const int MAXL = 17;
int N, Q, B;
long long arr[1 << (MAXL + 1)]; // 2^31 - 1이 int의 최대 범위. 안전하게 long long으로 선언

long long cal(int x, int y)
{
    int lo = x + B - 1, hi = y + B - 1;
    if (x > y)
    {
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    long long sum = 0;
    // lo == hi일 때에는 arr[lo(=hi)]의 값이 중복 덧셈될 수도 있겠으나
    // 밑의 if문 중 하나만 충족하기 때문에 그럴 일은 없음
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

void update(int a, int b)
{
    int idx = a + B - 1;
    arr[idx] = b;
    while ((idx /= 2) > 0)
    {
        arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (B = 1; B < N; B <<= 1)
        ; // init B
    for (int i = B; i < B + N; i++)
    { // init leaf node
        cin >> arr[i];
    }
    for (int i = B - 1; i > 0; i--)
    { // init parent node
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    for (int i = 0; i < Q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << cal(x, y) << '\n';
        update(a, b);
    }
}