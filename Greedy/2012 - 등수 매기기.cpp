#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
vector<int> grade;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        grade.push_back(a);
    }
    sort(grade.begin(), grade.end());
    long long sum = 0;
    for(int i = 0; i < N; i++){
        sum += abs(i + 1 - grade[i]);
    }
    cout << sum;
}