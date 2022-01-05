#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    while(!completion.empty()){
        string temp = completion.back();
        completion.pop_back();

        int size = participant.size();
        for(int i = 0; i < size; i++){
            if(participant[i] == temp){
                participant.erase(participant.begin() + i);
                break;
            }
        }
    }
    answer = participant[0];
    return answer;
}

int main(){
    vector<string> participant;
    vector<string> completion;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        participant.push_back(s);
    }
    for(int i = 0; i < n - 1; i++){
        string s;
        cin >> s;
        completion.push_back(s);
    }
    solution(participant, completion);
}