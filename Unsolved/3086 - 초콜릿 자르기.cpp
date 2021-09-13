#include<iostream>
#include<cstring>
using namespace std;

const int INF = 1000000000;
int N, M;
int cache[1000][1000];

bool outOfBound(int y, int x){
    return (y < 0 || y >= N) || (x < 0 || x >= M);
}

int solve(int y, int x){
    if(outOfBound(y, x)) return 0;
    if(cache[y][x] != -1){
        //cout << "1 : cache exist : " << y << ',' << x << " : " << cache[y][x] << endl;
        return cache[y][x];
    }
    if(N - y == M - x){
        cache[y][x] = 1;
        //cout << "2 : square : " << y << ',' << x << " : " << cache[y][x] << endl;
        return cache[y][x];
    }
    if(y == N - 1){
        cache[y][x] = M - x;
        //cout << "3 : y == N - 1 : " << y << ',' << x << " : " << cache[y][x] << endl;
        return cache[y][x];
    }
    if(x == M - 1){
        cache[y][x] = N - y;
        //cout << "4 : x == M - 1 : " << y << ',' << x << " : " << cache[y][x] << endl;
        return cache[y][x];
    }

    if((N - y) >= (M - x) * 3){
        cache[y][x] = 1 + solve(y + M - x, x);
    }
    else if((M - x) >= (N - y) * 3){
        cache[y][x] = 1 + solve(y, x + N - y);
    }
    else{
        int s;
        if(M - x < N - y){
            s = M - x;
        }
        else{
            s = N - y;
        }
        int min = INF;
        for(int i = s; i >= s / 2; i--){
            int temp;
            temp = solve(y + i, x) + solve(N - i, x + i);
            if(min > temp) min = temp;
            temp = solve(y, x + i) + solve(y + i, M - i);
            if(min > temp) min = temp;
            //cout << "for(" << i << ") : " << y << ',' << x << " : " << "min = " << min + 1 << endl;
        }
        cache[y][x] = min + 1;

        //cout << "all passed : " << y << ',' << x << " : " << cache[y][x] << endl;
    }
    return cache[y][x];
}

// greedy가 안되는 반례 : 6 x 7
int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    solve(0, 0);
    cout << cache[0][0];
}