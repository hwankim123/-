#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;

bool isPresent[46]; // [42] : *, [43] : +, [45] : -

long long solution(string expression)
{
    long long answer = 0;
    list<long long> numbers;
    list<char> params;
    int paramsNum = 0;
    list<char> kindOfParams;

    // string을 "연산자 list"와 "숫자 list"로 나눔
    string::iterator iter = expression.begin();
    int number = 0;
    int dist = 10;
    while (iter != expression.end())
    {
        if (*iter >= '0' && *iter <= '9')
        {
            number = number * dist + (*iter - '0');
        }
        else
        {
            isPresent[*iter] = true;
            numbers.push_back(number);
            params.push_back(*iter);
            number = 0;
        }
        iter++;
    }
    numbers.push_back(number);
    for (int i = 42; i <= 45; i++)
    {
        if (isPresent[i])
        {
            paramsNum++;
            kindOfParams.push_back(i);
        }
    }
    if (paramsNum == 0)
    {
        return numbers.front();
    }
    else if (paramsNum == 1)
    {
        list<long long>::iterator num = numbers.begin();
        list<char>::iterator par = params.begin();

        answer = *num++;
        while (par != params.end())
        {
            switch (*par++)
            {
            case '+':
                answer += *num++;
                break;
            case '-':
                answer -= *num++;
                break;
            case '*':
                answer *= *num++;
                break;
            }
        }
        answer = abs(answer);
    }
    else if (paramsNum == 2)
    {
        list<char>::iterator kindIt = kindOfParams.begin();
        char cases[2][2] = {{*kindIt, *(++kindIt)}, {*kindIt, *(--kindIt)}};

        for (int i = 0; i < 2; i++)
        {
            list<long long> tempNumbers = numbers;
            list<char> tempParams = params;
            for (int j = 0; j < 2; j++)
            {
                list<long long>::iterator num = tempNumbers.begin();
                list<char>::iterator par = tempParams.begin();
                while (par != tempParams.end())
                {
                    if (cases[i][j] == *par)
                    {
                        long long temp = *num;
                        num = tempNumbers.erase(num);
                        switch (*par)
                        {
                        case '+':
                            *num = temp + *num;
                            break;
                        case '-':
                            *num = temp - *num;
                            break;
                        case '*':
                            *num = temp * *num;
                            break;
                        }
                        par = tempParams.erase(par);
                    }
                    else
                    {
                        num++;
                        par++;
                    }
                }
            }
            if (abs(tempNumbers.front()) > answer)
            {
                answer = abs(tempNumbers.front());
            }
        }
    }
    else
    {
        list<char>::iterator kindIt = kindOfParams.begin();
        char cases[6][3] = {
            {*kindIt, *(++kindIt), *(++kindIt)},     // 1 2 3
            {*kindIt, *(--kindIt), *(--kindIt)},     // 3 2 1
            {*kindIt, *(++(++kindIt)), *(--kindIt)}, // 1 3 2
            {*kindIt, *(--kindIt), *(++(++kindIt))}, // 2 1 3
            {*kindIt, *(--(--kindIt)), *(++kindIt)}, // 3 1 2
            {*kindIt, *(++kindIt), *(--(--kindIt))}  // 2 3 1
        };

        for (int i = 0; i < 6; i++)
        {
            list<long long> tempNumbers = numbers;
            list<char> tempParams = params;
            for (int j = 0; j < 3; j++)
            {
                list<long long>::iterator num = tempNumbers.begin();
                list<char>::iterator par = tempParams.begin();
                while (par != tempParams.end())
                {
                    if (cases[i][j] == *par)
                    {
                        long long temp = *num;
                        num = tempNumbers.erase(num);
                        switch (*par)
                        {
                        case '+':
                            *num = temp + *num;
                            break;
                        case '-':
                            *num = temp - *num;
                            break;
                        case '*':
                            *num = temp * *num;
                            break;
                        }
                        par = tempParams.erase(par);
                    }
                    else
                    {
                        num++;
                        par++;
                    }
                }
            }
            cout << cases[i][0] << ' ' << cases[i][1] << ' ' << cases[i][2] << ' ' << tempNumbers.size() << ' ';
            cout << abs(tempNumbers.front()) << endl;
            if (abs(tempNumbers.front()) > answer)
            {
                answer = abs(tempNumbers.front());
            }
        }
    }
    return answer;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s);
}