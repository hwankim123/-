#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAXK 4
#define MAXN 10

int n, k;
bool Visit[MAXN];
int D[MAXK];
int card[MAXN];
bool matrix[100000000];
int Top;
int result;

void check(){
    int i = MAXK - 1;
    int digit = 0;
    int sum = 0;
    while(i >= 0){
        if(D[i] < 10 && D[i] > 0){
            sum += D[i] * round(pow(10, digit++));
        } else if(D[i] >= 10){
            sum += D[i] * round(pow(10, digit));
            digit += 2;
        }
        i--;
    }
    //cout << sum << endl;
    if(!matrix[sum]){
        matrix[sum] = true;
        result++;
    }
}

void backtracking(){
    if(Top == k){
        check();
        return;
    }
    for(int i = 0; i < n; i++){
        if(!Visit[i]){
            Visit[i] = true;
            D[Top++] = card[i];
            //cout << "D : ";
            //for(int j = 0; j < Top; j++){
            //    cout << D[j] << ' ';
            //} cout << endl;
            backtracking();
            Top--;
            Visit[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }
    Top = 0;
    backtracking();
    cout << result << '\n';

}