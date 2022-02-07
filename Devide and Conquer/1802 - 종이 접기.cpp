#include<iostream>
#include<string>
using namespace std;

int T;
string s;

bool solve(int lo){
    if(s.size() == 1) return true;
    if(s.size() != 3 && lo == s.size() / 2){
        return true;
    }
    if(s.size() == 3){
        if(s[0] != s[2]) return true;
        else return false;
    }
    bool flag = true;
    for(int i = 0; i < lo; i++){
        int j = lo * 2 - i;
        if(s[i] == s[j]){
            flag = false;
            break;
        }
    }
    if(!flag){
        return false;
    }
    flag = true;
    for(int i = 0; i < lo * 2 + 1; i++){
        int j = s.size() - 1 - i;
        if(s[i] == s[j]){
            flag = false;
            break;
        }
    }
    if(flag){
        return solve(lo * 2 + 1);
    } else{
        return false;
    }

}

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> s;
        if(solve(1)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}