#include<iostream>
#include <string>
#include <string.h>
#include <vector>
// https://twpower.github.io/139-hash-table-implementation-in-cpp
using namespace std;

#define MAX_TABLE 100000
#define MAX_KEY 21
struct Node {
    char key[MAX_KEY];
    int value;
    Node *next;
};

int Hash(const char *str){
    int h = 401;
    int c;

    // return되는 값이 인덱스로 활용되기 때문에
    // 반드시 vector 최대 크기인 MAX_TABLE로 나머지 연산을 해줘야 함.
    while(*str != '\0'){
        h = ((h << 4) + (int)(*str)) % MAX_TABLE;
        str++;
    }

    return h % MAX_TABLE;
}

void add(Node *tb[], const char *key, int value = 1){
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;

    int index = Hash(key);

    if(tb[index] == NULL){
        tb[index] = new_node;
    }
    else{
        Node *cur = tb[index];

        while(cur != NULL){
            // 이미 해당 key에 대한 값이 존재할 때. 갱신
            if(strcmp(cur->key, key) == 0){
                cur->value++;
                return;
            }
            cur = cur->next;
        }
        new_node->next = tb[index];
        tb[index] = new_node;
    }
}

bool destroy(Node *tb[], const char *key){
    int index = Hash(key);

    if(tb[index] == NULL){
        return false;
    }

    if(strcmp(tb[index]->key, key) == 0){
        if(tb[index]->value > 1){
            tb[index]->value--;
        }
        else if(tb[index]->value == 1){
            Node *first = tb[index];
            tb[index] = tb[index] -> next;
            free(first);
        }
        return true;
    }

    else{
        Node *cur = tb[index] -> next;
        Node *prev = tb[index];

        while(cur != NULL && strcmp(cur -> key, key) != 0){
            prev = cur;
            cur = cur->next;
        }
        if(cur == NULL) return false;

        if(cur->value > 1){
            cur->value--;
        }
        else if(cur->value == 1){
            prev->next = cur->next;
            free(cur);
        }
        return true;
    }
}

bool find(Node *tb[], const char *key){
    int index = Hash(key);
    Node *cur = tb[index];

    while(cur != NULL){
        if(strcmp(cur->key, key) == 0){
            destroy(tb, key);
            return true;
        }
        cur = cur->next;
    }
    return false;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash table 생성 -> key : value = 선수 : 1
    Node *hashTable[MAX_TABLE];

    int size = participant.size();
    for(int i = 0; i < size; i++){
        char part[MAX_KEY];
        int j;
        for(j = 0; j < participant[i].size(); j++){
            part[j] = participant[i][j];
        }
        part[j] = '\0';
        add(hashTable, part);
    }
    while(!completion.empty()){
        string temp = completion.back();
        completion.pop_back();
        
        char comp[MAX_KEY];
        int i;
        for(i = 0; i < temp.size(); i++){
            comp[i] = temp[i];
        }
        comp[i] = '\0';
        find(hashTable, comp);
    }
    for(int i = 0; i < size; i++){
        char part[MAX_KEY];
        int j;
        for(j = 0; j < participant[i].size(); j++){
            part[j] = participant[i][j];
        }
        part[j] = '\0';
        if(find(hashTable, part)){
            return participant[i];
        }
    }
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
    cout << solution(participant, completion);
}