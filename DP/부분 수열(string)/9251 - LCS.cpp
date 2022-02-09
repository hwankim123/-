#include <iostream>
using namespace std;

#define MAXS 1111

char s1[MAXS], s2[MAXS];
int cache[MAXS][MAXS]; // cache[i][j] : s1의 1~i 부분수열과 s2의 1~j 부분수열 내에서의 LCS
int s1Len, s2Len;      // 각각 s1과 s2 문자열의 길이

// cache[i][j]가 갱신될 수 있는지를 판단하는 함수
// s1의 i번째 문자와 s2의 j번째 문자가 각각의 부분수열에 추가되어야만 최장 부분수열 길이가 +1 될 수 있음을 보장하는 조건문
// 만약 둘 중 하나의 조건이 false라면, [i][j]번째를 탐색하기 이전에 이미 + 1 높은 LCS를 찾아놓았다는 뜻임
bool allSame(int i, int j)
{
    return (cache[i - 1][j - 1] == cache[i - 1][j]) && (cache[i - 1][j - 1] == cache[i][j - 1]);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    cin >> s1 >> s2;
    int i = 0, j = 0;
    while (true)
    {
        if (s1[i] == '\0')
        {
            s1Len = i;
            break;
        }
        j = 0;
        while (true)
        {
            if (s2[j] == '\0')
            {
                s2Len = j;
                break;
            }
            if (s1[i] == s2[j] && allSame(i + 1, j + 1))
            {
                cache[i + 1][j + 1] = cache[i][j] + 1;
            }
            else
            {
                cache[i + 1][j + 1] = max(cache[i][j + 1], cache[i + 1][j]);
            }
            j++;
        }
        i++;
    }
    cout << cache[s1Len][s2Len];
}