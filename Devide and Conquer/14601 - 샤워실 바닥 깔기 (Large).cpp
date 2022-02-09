#include <iostream>
using namespace std;

int N, Y, X;

int main()
{
    cin >> N >> X >> Y;
    Y = Y - (1 << N);
    X--;
    cout << Y << X;
}