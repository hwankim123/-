#include<iostream>
using namespace std;

int N;
long long cache[100];

long long fib(int n){
    if(n != 0 && cache[n] == 0){
        cache[n] = fib(n - 1) + fib(n - 2);
    }
    return cache[n];
}

int main(){
    cin >> N;
    cache[0] = 0; cache[1] = 1;
    cout << fib(N);
}