#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 100000000, MAX_V = 100000;
int N, K;
priority_queue<pair<int, int> > pq;
vector<int> dist(MAX_V + 1, INF);

bool promising(int here){
    return here >= 0 && here <= MAX_V;
}

int main(){
    cin >> N >> K;
    pq.push(make_pair(0, N));
    dist[N] = 0;
    if(K <= N) cout << N - K;
    else{
        while(!pq.empty()){
            int here = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if(here == K) break;
            if(dist[here] < cost) continue;

            if(here < K && promising(here + 1) && cost + 1 < dist[here + 1]){
                dist[here + 1] = cost + 1;
                pq.push(make_pair(-(cost + 1), here + 1));
            }
            if(promising(here - 1) && cost + 1 < dist[here - 1]){
                dist[here - 1] = cost + 1;
                pq.push(make_pair(-(cost + 1), here - 1));
            }
            if(here != 0){
                while(here < K){
                    here *= 2;
                    if(promising(here) && cost < dist[here]){
                        dist[here] = cost;
                        pq.push(make_pair(-cost, here));
                    }
                }
            }
        }
        cout << dist[K];
    }
}