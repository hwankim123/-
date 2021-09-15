#include<iostream>
using namespace std;

int N, B, C;
int adj[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> adj[i];
    }
    cin >> B >> C;
    long long int result = 0;
    for(int i = 0; i < N; i++){
        adj[i] -= B;
        result++;
        if(adj[i] > 0){
            int temp = adj[i] / C;
            if(adj[i] % C != 0){
                temp++;
            }
            result += temp;
        }
    }
    cout << result;
}
