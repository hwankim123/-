#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max = 0, min = 0;
    sort(lottos.rbegin(), lottos.rend());
    sort(win_nums.rbegin(), win_nums.rend());
    int i = 0, j = 0;
    while(j < 6){
        if(lottos[i] > win_nums[j]){
            i++;
        }
        else if(lottos[i] < win_nums[j]){
            j++;
        }
        else{
            max++;
            min++;
            i++;
            j++;
        }
    }
    cout << i << ' ' << j;
    for(int k = i; k < 6; k++){
        max++;
    }
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}

int main(){
    vector<int> lottos(6, 0);
    vector<int> win_nums(6, 0);
    for(int i = 0; i < 6; i++){
        cin >> lottos[i];
    }
    for(int i = 0; i < 6; i++){
        cin >> win_nums[i];
    }
    vector<int> result = solution(lottos, win_nums);
    cout << result[0] << ' ' << result[1];
}