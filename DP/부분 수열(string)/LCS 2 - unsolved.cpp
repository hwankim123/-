#include <iostream>
using namespace std;

#define MAXS 1111

char s1[MAXS], s2[MAXS];
int cache[MAXS][MAXS];
char resultS[MAXS];
int s1Len, s2Len;

bool allSame(int i, int j)
{
    return (cache[i - 1][j - 1] == cache[i - 1][j]) && (cache[i - 1][j - 1] == cache[i][j - 1]) && (cache[i - 1][j] == cache[i][j - 1]);
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
        if (s1[i] != '\0')
        {
            s1Len = i;
            break;
        }
        j = 0;
        while (true)
        {
            if (s2[j] != '\0')
            {
                if (s1Len == 0)
                {
                    s2Len == j;
                }
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
}