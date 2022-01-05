#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

string cmd;
vector<string> vCmd;
stack<int> sInput;
stack<int> sNUM;
stack<int> sSaveNUM; // sNUM.top의 결과물을 임시로 저장하는 stack
int N;
bool programError = false;

bool isEmpty(){
    if(sInput.empty()){
        programError = true;
    } else {
        programError = false;
    }
    return programError;
}

bool checkZeroDIV(int num){
    return (programError = (num == 0));
}

bool checkIntOverflow(int num){
    return (programError = (num > 1000000000));
}

pair<int, int> popTwo(){
    if(isEmpty()){
        return make_pair(0, 0);
    }
    int temp1 = sInput.top();
    sInput.pop();
    int temp2 = sInput.top();
    sInput.pop();
    return make_pair(temp1, temp2);
}

int main(){
    cin >> cmd;
    while(cmd != "QUIT"){
        vCmd.push_back(cmd);
        if(cmd == "NUM"){
            int n;
            cin >> n;
            sNUM.push(n);
        } else if(cmd == "END"){
            cin >> N;
            for(int i = 0; i < N; i++){
                int n;
                cin >> n;
                sInput.push(n);
                // 연산 시작
                for(int j = 0; j < vCmd.size(); j++){
                    if(vCmd[j] == "NUM"){
                        int num = sNUM.top();
                        sInput.push(num);
                        sSaveNUM.push(num);
                        sNUM.pop();
                    } else if(vCmd[j] == "POP"){
                        if(isEmpty()){
                            break;
                        }
                        sInput.pop();
                    } else if(vCmd[j] == "INV"){
                        if(isEmpty()){
                            break;
                        }
                        int num = -sInput.top();
                        sInput.pop();
                        sInput.push(num);
                    } else if(vCmd[j] == "DUP"){
                        int num = sInput.top();
                        sInput.push(num);
                    } else if(vCmd[j] == "SWP"){
                        pair<int, int> tempPair = popTwo(); 
                        sInput.push(tempPair.first);
                        sInput.push(tempPair.second);
                    } else if(vCmd[j] == "ADD"){
                        pair<int, int> tempPair = popTwo(); 
                        int result = tempPair.first + tempPair.second;
                        if(checkIntOverflow(result)){
                            break;
                        }
                        sInput.push(result);
                    } else if(vCmd[j] == "SUB"){
                        pair<int, int> tempPair = popTwo(); 
                        sInput.push(tempPair.second - tempPair.first); 
                    } else if(vCmd[j] == "MUL"){
                        pair<int, int> tempPair = popTwo(); 
                        int result = tempPair.first * tempPair.second;
                        if(checkIntOverflow(result)){
                            break;
                        }
                        sInput.push(result);                       
                    } else if(vCmd[j] == "DIV"){
                        pair<int, int> tempPair = popTwo();
                        if(checkZeroDIV(tempPair.first)){
                            break;
                        }
                        sInput.push(abs(tempPair.second) / tempPair.first);                         
                    } else if(vCmd[j] == "MOD"){
                        pair<int, int> tempPair = popTwo(); 
                        if(checkZeroDIV(tempPair.first)){
                            break;
                        }
                        sInput.push(tempPair.second % tempPair.first);                         
                    }
                }
                while(!sSaveNUM.empty()){
                    int temp = sSaveNUM.top();
                    sSaveNUM.pop();
                    sNUM.push(temp);
                }
            }
        }
    }
}
