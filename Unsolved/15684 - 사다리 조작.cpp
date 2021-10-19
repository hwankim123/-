#include<iostream>
#include<stdio.h>
using namespace std;

int N, M, H;
int adj[30][11]; // 0 : false
int result[11];

void print() {
    cout << "사다리 \n";
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= N; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }
}

bool check() {
    //print();
    for (int j = 1; j < N; j++) {
        int here = j;
        bool flag = true;
        for (int i = 1; i <= H; i++) {
            if (here < N) {
                if (adj[i][here] == 1) {
                    //cout << "here++" << endl;
                    here++;
                    continue;
                }
            }
            if (here > 1) {
                if (adj[i][here - 1] == 1) {
                    //cout << "here--" << endl;
                    here--;
                    continue;
                }
            }
        }
        if (here != j) {
            //cout << "ckech fail : j is " << j << "and here is " << here << endl;
            return false;
        }
    }
    //cout << "all passed" << endl;
    return true;
}

bool find(int c) {
    //cout << "\nfind(" << c << ")\n";
    if (c == 0) {
        return check();
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            //cout << i << ", " << j << '/';
            if (adj[i][j] == 1) continue;
            else {
                bool flag = true;
                if (j < N) {
                    if (flag && adj[i][j + 1] != 0) {
                        //cout << "인접한 곳에 사다리 있음\n";
                        flag = false;
                    }
                }
                if (j > 1) {
                    if (flag && adj[i][j - 1] != 0) {
                        //cout << "인접한 곳에 사다리 있음\n";
                        flag = false;
                    }
                }
                if (flag) {
                    adj[i][j] = 1;
                    //cout << endl;
                    //cout << "go deep\n";
                    if (find((--c)++)) {
                        return true;
                    }
                    else {
                        adj[i][j] = 0;
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    int count = 0;
    if (check()) {
        cout << count;
        return;
    }
    else {
        count++;
        while (count <= 3) {
            if (find(count)) {
                cout << count;
                return;
            }
            count++;
        }
        if (count > 3) {
            cout << -1;
            return;
        }
    }
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    solve();
}