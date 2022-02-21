#include<iostream>
using namespace std;

long long A, B, C;

long long solve(int n, int m){
    if(m == 1){
        return n % C;
    }
    if(m == 2){
        return ((n % C) * (n % C)) % C;
    }
    if(m % 2 == 0){
        long long half = solve(n, m / 2);
        return (half * half) % C;
    } else{
        long long half1 = solve(n, m / 2);
        long long half2 = (half1 * (n % C)) % C;
        return (half1 * half2) % C;
    }
}

int main(){
    cin >> A >> B >> C;
    cout << solve(A, B) % C;
}