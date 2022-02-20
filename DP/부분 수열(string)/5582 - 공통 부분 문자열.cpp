#include <iostream>
#include <vector>
using namespace std;

#define MAXS 4001

char s1[MAXS], s2[MAXS];
int cache[MAXS][MAXS];
int s1Len, s2Len;
int result;

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
        if(s1[i] == '\0'){
            s1Len = i;
            break;
        }
        j = 0;
        while (true)
        {
            if(s2[j] == '\0'){
                s2Len = j;
                break;
            }
            if(s1[i] == s2[j]){
                cache[i + 1][j + 1] = cache[i][j] + 1;
                if(result < cache[i + 1][j + 1]){
                    result = cache[i + 1][j + 1];
                }
            }
            j++;
        }
        i++;
    }
    cout << result;
}