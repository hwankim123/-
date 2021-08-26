#include<iostream>
#include<vector>
#include<string>
using namespace std;

int R, C;
vector<string> adj;
const string INF = "zzzzzzzzzzzzzzzzzzzz";
string result = INF;

void solve(int i, string s);

int main(){
    cin >> R >> C;
    adj = vector<string>(R, string());
    for(int i = 0; i < R; i++){
        cin >> adj[i];
    }
    for(int i = 0; i < R; i++){
        string s = adj[i];
        solve(i, s);
    }
    for(int i = 0; i < C; i++){
        string s = "";
        for(int j = 0; j < R; j++){
            s += adj[j][i];
        }
        solve(i, s);
    }
    cout << result << endl;
}

void solve(int i, string s){
    int startIndex = 0;
    int endIndex = s.find('#');
    string temp = INF;
    while(endIndex != -1){
        if(endIndex - startIndex > 1){
            if(temp.compare(s.substr(startIndex, endIndex - startIndex)) > 0){
                temp = s.substr(startIndex, endIndex - startIndex);
            }
        }
        startIndex = endIndex + 1;
        s[endIndex] = '$';
        endIndex = s.find('#');
    }
    if(s.size() - startIndex > 1){
        if(temp.compare(s.substr(startIndex, s.size() - startIndex)) > 0){
            temp = s.substr(startIndex, s.size() - startIndex);
        }
    }
    if(temp.find('#') == -1){
        if(result.compare(temp) > 0) result = temp;
    }
}   