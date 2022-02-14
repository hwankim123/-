#include <iostream>
#include<algorithm>
using namespace std;

#define MAXN 1000

int n;
int box[MAXN];
int cache[MAXN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> box[i];
        cache[i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(box[j] < box[i] && cache[j] == cache[i]) cache[i]++;
        }
    }
    sort(cache, cache + n);
    cout << cache[n - 1];
}