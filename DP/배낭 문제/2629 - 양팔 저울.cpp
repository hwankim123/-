#include <iostream>
#include <cmath>
using namespace std;

int chu;
int chuWeight[30];
int goosl;
int gooslWeight[7];
bool cache[31][15001];

void solve(int i, int w)
{
    if (i > chu || cache[i][w])
        return;
    cache[i][w] = true;
    solve(i + 1, w + chuWeight[i]);
    solve(i + 1, abs(w - chuWeight[i]));
    solve(i + 1, w);
}

int main()
{
    cin >> chu;
    for (int i = 0; i < chu; i++)
    {
        cin >> chuWeight[i];
    }

    solve(0, 0);

    cin >> goosl;
    for (int i = 0; i < goosl; i++)
    {
        cin >> gooslWeight[i];

        if (gooslWeight[i] > 15000)
            cout << "N ";
        else if (cache[chu][gooslWeight[i]])
            cout << "Y ";
        else
            cout << "N ";
    }
}