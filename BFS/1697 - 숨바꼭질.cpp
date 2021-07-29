#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N, K;
vector<int> adj(1000001, 0);

int main(){
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    if(N == K) cout << 0;
    else{
        while(!q.empty()){
            int here = q.front();
            //cout << here << ' ';
            q.pop();
            if(here + 1 == K) {
                cout << adj[here] + 1;
                break;
            }
            else{
                if(here + 1 != N && here + 1 < 100001 && adj[here + 1] == 0){
                    q.push(here + 1);
                    adj[here + 1] = adj[here] + 1;
                }
            } 

            if(here - 1 == K) {
                cout << adj[here] + 1;
                break;
            }
            else {
                if(here - 1 != N && here - 1 > 0 && adj[here - 1] == 0){
                    q.push(here - 1);
                    adj[here - 1] = adj[here] + 1;
                }
            }

            if(here * 2 == K) {
                cout << adj[here] + 1;
                break;
            }
            else {
                if(here * 2 != N && here * 2 < 100001 && adj[here * 2] == 0){
                    q.push(here * 2);
                    adj[here * 2] = adj[here] + 1;
                }
            }
        }
    }
}