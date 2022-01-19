#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long dice[6];

const int INF = 987654321;

long long threePointer[3];
void findCorner()
{
    int result = INF;
    int ABC = dice[0] + dice[1] + dice[2];
    if (result > ABC)
    {
        result = ABC;
        threePointer[0] = dice[0];
        threePointer[1] = dice[1];
        threePointer[2] = dice[2];
    }
    int ABD = dice[0] + dice[1] + dice[3];
    if (result > ABD)
    {
        result = ABD;
        threePointer[0] = dice[0];
        threePointer[1] = dice[1];
        threePointer[2] = dice[3];
    }
    int ACE = dice[0] + dice[2] + dice[4];
    if (result > ACE)
    {
        result = ACE;
        threePointer[0] = dice[0];
        threePointer[1] = dice[2];
        threePointer[2] = dice[4];
    }
    int ADE = dice[0] + dice[3] + dice[4];
    if (result > ADE)
    {
        result = ADE;
        threePointer[0] = dice[0];
        threePointer[1] = dice[3];
        threePointer[2] = dice[4];
    }
    int BCF = dice[1] + dice[2] + dice[5];
    if (result > BCF)
    {
        result = BCF;
        threePointer[0] = dice[1];
        threePointer[1] = dice[2];
        threePointer[2] = dice[5];
    }
    int BDF = dice[1] + dice[3] + dice[5];
    if (result > BDF)
    {
        result = BDF;
        threePointer[0] = dice[1];
        threePointer[1] = dice[3];
        threePointer[2] = dice[5];
    }
    int CEF = dice[2] + dice[4] + dice[5];
    if (result > CEF)
    {
        result = CEF;
        threePointer[0] = dice[2];
        threePointer[1] = dice[4];
        threePointer[2] = dice[5];
    }
    int DEF = dice[3] + dice[4] + dice[5];
    if (result > DEF)
    {
        result = DEF;
        threePointer[0] = dice[3];
        threePointer[1] = dice[4];
        threePointer[2] = dice[5];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i]; // [0]:A [1]:B [2]:C [3]:D [4]:E [5]:F
    }
    if (N == 1)
    {
        sort(dice, dice + 6);
        cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
        return 0;
    }
    findCorner();
    sort(threePointer, threePointer + 3);
    long long three = threePointer[0] + threePointer[1] + threePointer[2];
    long long two = three - threePointer[2];
    long long one = two - threePointer[1];

    cout << three * 4 + two * ((N - 2) * 4 + (N - 1) * 4) + one * ((N - 2) * (N - 2) + (N - 1) * (N - 2) * 4);
}