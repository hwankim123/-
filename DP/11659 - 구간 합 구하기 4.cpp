#include<iostream>
using namespace std;

// 누적 합

int n, m;
int arr[100001];
int sum[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
    }
}