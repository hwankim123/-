#include<iostream>
#include<algorithm>
using namespace std;

long long N, S;
long long arr[100000];
long long lo, hi, sum, len = 1000000;

int main(){
    cin >> N >> S;
    for(long long i = 0; i < N; i++){
        cin >> arr[i];
    }
    sum = arr[0];
    while(hi != N){
        //cout << "lo / hi : " << lo << ' ' << hi << "sum : " << sum << endl;

        if(sum < S){
            hi++;
            sum += arr[hi];
        } else{
            len = (len > hi - lo + 1) ? hi - lo + 1 : len;
            sum -= arr[lo];
            lo++;
        }
    }
    if(len == 1000000) cout << 0;
    else cout << len;
}