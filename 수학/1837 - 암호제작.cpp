#include <iostream>
using namespace std;

const int MAX = 100;
char P[MAX]; // 10^100은 long long으로도 커버 불가능이래
int K;

int main()
{
    cin >> P >> K;
    for (int i = 0; i < MAX; i++)
    {
        cout << P[i];
    }
    cout << K;
}