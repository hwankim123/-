#include<iostream>
using namespace std;

int N, M;
int adj[8][8];
int c, wallC;
pair<int, int> cctv[8];
int visited[8][8];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int findAll(int y, int x, int* dir){
    int sum = 0;
    for(int i = 0; i < 4; i++){
        int temp = 0;
        int ty = y;
        int tx = y;
        while((ty + dy[i] >= 0 && ty + dy[i] < N && tx + dx[i] >= 0 && tx + dx[i] < M) && adj[ty + dy[i]][tx + dx[i]] != 6){
            temp++;
            ty += dy[i];
            tx += dx[i];
        }
        dir[i] = temp;
        sum += temp;
        cout << sum << " ~ ";
    }
    return sum;
}

void fillWithExc(int y, int x, int j){
    while((y + dy[j] >= 0 && y + dy[j] < N && x + dx[j] >= 0 && x + dx[j] < M) 
        && adj[y + dy[j]][x + dx[j]] != 6){
            y += dy[j];
            x += dx[j];
            adj[y][x] = 7;
    }
}

int solve(){
    int result = 0;
    for(int i = 0; i < c; i++){
        cout << i << " : " << endl;

        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cout << adj[j][k] << ' ';
            }
            cout << endl;
        }
        int sum = 0;
        int maxJ = 0;
        int saveY = cctv[i].first;
        int saveX = cctv[i].second;
        int dir[4] = {0, 0, 0, 0};
        switch(adj[saveY][saveX]){
            case 1:
                for(int j = 0; j < 4; j++){
                    int temp = 0;
                    int y = saveY;
                    int x = saveX;
                    while((y + dy[j] >= 0 && y + dy[j] < N && x + dx[j] >= 0 && x + dx[j] < M) && adj[y + dy[j]][x + dx[j]] != 6){
                        if(adj[y + dy[j]][x + dx[j]] != 7){
                            temp++;
                        }
                        y += dy[j];
                        x += dx[j];
                        visited[y][x] = 1;
                        cout << y << ' ' << x << " / ";
                    }
                    if(sum < temp) {
                        sum = temp;
                        maxJ = j;
                    }
                    cout << "sum " << sum << endl;
                }
                fillWithExc(saveY, saveX, maxJ);
                break;
            case 2:
                for(int j = 0; j < 2; j++){
                    int temp = 0;
                    int y = saveY;
                    int x = saveX;
                    while((y + dy[j] >= 0 && y + dy[j] < N && x + dx[j] >= 0 && x + dx[j] < M) && adj[y + dy[j]][x + dx[j]] != 6){
                        if(adj[y + dy[j]][x + dx[j]] != 7){
                            temp++;
                        }
                        y += dy[j];
                        x += dx[j];
                        cout << y << ' ' << x << " / ";
                    }
                    y = saveY;
                    x = saveX;
                    while((y + dy[j + 2] >= 0 && y + dy[j + 2] < N && x + dx[j + 2] >= 0 && x + dx[j + 2] < M) && adj[y + dy[j + 2]][x + dx[j + 2]] != 6){
                        if(adj[y + dy[j]][x + dx[j]] != 7){
                            temp++;
                        }
                        y += dy[j + 2];
                        x += dx[j + 2];
                        cout << y << ' ' << x << " / ";
                    }
                    if(sum < temp) {
                        sum = temp;
                        maxJ = j;
                    }
                    cout << "sum " << sum << endl;
                }
                fillWithExc(saveY, saveX, maxJ);
                fillWithExc(saveY, saveX, maxJ + 2);
                break;
            case 3:
                for(int j = 0; j < 3; j += 2){ // 01 / 23 
                    int temp = 0;
                    int y = saveY;
                    int x = saveX;
                    while((y + dy[j] >= 0 && y + dy[j] < N && x + dx[j] >= 0 && x + dx[j] < M) && adj[y + dy[j]][x + dx[j]] != 6){
                        if(adj[y + dy[j]][x + dx[j]] != 7){
                            temp++;
                        }
                        y += dy[j];
                        x += dx[j];
                        cout << y << ' ' << x << " / ";
                    }
                    y = saveY;
                    x = saveX;
                    while((y + dy[j + 1] >= 0 && y + dy[j + 1] < N && x + dx[j + 1] >= 0 && x + dx[j + 1] < M) && adj[y + dy[j + 1]][x + dx[j + 1]] != 6){
                        if(adj[y + dy[j]][x + dx[j]] != 7){
                            temp++;
                        }
                        y += dy[j + 1];
                        x += dx[j + 1];
                        cout << y << ' ' << x << " / ";
                    }
                    if(sum < temp) {
                        sum = temp;
                    }
                    cout << "sum " << sum << endl;
                }
                fillWithExc(saveY, saveX, maxJ);
                fillWithExc(saveY, saveX, maxJ + 1);
                break;
            case 5:
                sum = findAll(saveY, saveX, dir);
                cout << "sum " << sum << endl;
                for(int j = 0; j < 4; j++){
                    fillWithExc(saveY, saveX, j);
                }
                break;
            case 4:
                int tempSum = findAll(saveY, saveX, dir);
                for(int j = 0; j < 4; j++){
                    int temp = tempSum - dir[j];
                    if(sum < temp){
                        sum = temp;
                        maxJ = j;
                    }
                    cout << "sum " << sum << endl;
                }
                for(int j = 0; j < 4; j++){
                    if(j == maxJ) continue;
                    fillWithExc(saveY, saveX, j);
                }
                break;
        }
        result += sum;
    }
    return result;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
            if(adj[i][j] > 0 && adj[i][j] < 6){
                cctv[c] = make_pair(i, j);
                c++;
            }
            else if(adj[i][j] == 6){
                wallC++;
            }
        }
    }
    cout << N * M << " " << wallC << " " << c << endl;
    cout << N * M - solve() - wallC - c;
}