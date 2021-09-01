#include<iostream> 
using namespace std;

int main() {
    long long int n;
    cin >> n;
    for(long long int i = 1;; i++){
        long long int total = i;
        for(int j = 0; j <= i; j++){
            total = total + (total + 1);
        }
        if(n <= total){
            cout << i;
            return 0;
        }
    }
}
