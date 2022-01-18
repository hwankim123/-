#include <iostream>
using namespace std;

#define INF 1023

// cache[i][j] : 자릿수가 i이면서 i의 자리 수는 j인 "감소하는 수"들의 "개수"를 저장.
// 감소하는 수는 10의 자리 수를 넘어가지 않음. 9876543210이 최대
// cache[i(i >= 1)][0]은 필요 없는 값
int cache[10][10];
long long result;

long long pow10(int dist)
{
    long long result = 1;
    for (int i = 0; i < dist; i++)
    {
        result *= 10;
    }
    return result;
}

int startDist = 0;

void solve(int n, int dist)
{
    if (n <= 1 && dist <= 0)
        return;
    bool flag = false;
    int temp = 0;
    for (int i = dist; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            temp += cache[i][j];
            if (temp >= n)
            {
                if (startDist == 0)
                {
                    startDist = i;
                    dist = i;
                }
                result += j * pow10(dist);
                solve(n - temp + cache[i][j], dist - 1);
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n >= INF)
        cout << -1; // 1022번째 감소하는 수가 9876543210이므로, 1023번째부턴 -1 출력
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            cache[0][i] = 1;
        }
        for (int i = 1; i <= 19; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cache[i][j] = cache[i - 1][j - 1] + cache[i][j - 1];
            }
        }
        /*
        * cache 출력
        */
        // for(int i = 0; i <= 19; i++){
        //     for(int j = 0; j <= 9; j++){
        //         cout << cache[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        /*
        * 0번째 ~ n번째 감소하는 수를 모두 출력
        */
        // for(int i = 0; i < n + 1; i++){
        //     solve(i + 1, startDist);
        //     cout << i + 1 << ' ' << result << endl;
        //     result = 0;
        //     startDist = 0;
        // }

        // n이 아니라 n+1를 넣는 이유는 0번째 감소하는 수가 0인 것을 세기 위함(0은 덧셈에 들어가지 않기 때문)
        solve(n + 1, startDist);
        cout << result;
    }
}