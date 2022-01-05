#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N, K, digit;
const int MAX_V = 1000000;
vector<bool> explored;

int swap(int here, int i, int j){
    int x = here % (int)pow(10, i+1);
    x = (x / (int)pow(10, i));
    int y = here % (int)pow(10, j+1);
    y = (y / (int)pow(10, j));
    int diff = x - y;
    if(diff > 0){
        here -= diff*((int)pow(10, i));
        here += diff*((int)pow(10, j));
    } else if(diff < 0){
        here += diff*((int)pow(10, i));
        here -= diff*((int)pow(10, j));
    }
    return here;
}

int main(){
    cin >> N >> K;
    int saveN = N;
    while(saveN != 0){
        saveN /= 10;
        digit++;
    }
    cout <<"dgit" << digit << endl;
    vector<int>distance = vector<int>(MAX_V, -1);
    queue<int> q;
    q.push(N);
    distance[N] = 0;
    for(int i = 0; i < K; i++){
        int here = q.front();
        q.pop();
        for(int i = 0; i < digit - 1; i++){
            for(int j = i + 1; j < digit; j++){
                int there = swap(here, i, j);
                if(distance[there] == -1){
                    distance[there] = i + 1;
                    q.push(there);
                }
            }
        }
    }
    for(int i = 0; i < 322; i++){
        cout << distance[i] << ' ';
    }
}