#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int dy[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int dx[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
int n;

string solution(vector<int>numbers, string hand){
    string answer = "";
    int ly = 3, lx = 0, ry = 3, rx = 2;
    for(int i = 0; i < n; i++){
        cout << "l:" << ly << ' ' << lx << "r:" << ry << ' ' << rx << endl;
            cout << "trial" << numbers[i]<<endl;
        switch(numbers[i]){
            case 1:
            case 4:
            case 7:
                answer += 'L';
                ly = dy[numbers[i]];
                lx = dx[numbers[i]];
                break;
            case 3:
            case 6:
            case 9:
                answer += 'R';
                ry = dy[numbers[i]];
                rx = dx[numbers[i]];
                break;
            case 0:
            case 2:
            case 5:
            case 8:
                int distL = abs(ly - dy[numbers[i]]) + abs(lx - dx[numbers[i]]);
                int distR = abs(ry - dy[numbers[i]]) + abs(rx - dx[numbers[i]]);
                cout << distL << ' ' << distR << endl;
                if((distL < distR) || (distL == distR && hand == "left")){
                    answer += 'L';
                    ly = dy[numbers[i]];
                    lx = dx[numbers[i]];
                }
                else if((distL > distR) || (distL == distR && hand == "right")){
                    answer += 'R';
                    ry = dy[numbers[i]];
                    rx = dx[numbers[i]];
                }
                break;
        }
    }
    return answer;
}

int main(){
    vector<int> numbers(1000, 0);
    string hand;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cin >> hand;
    cout << solution(numbers, hand);
}