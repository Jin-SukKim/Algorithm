#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<char, int> p;
    for (char& c : X)
        p[c]++;
    
    priority_queue<char> max;
    for (char& c : Y)
    {
        if (p[c])
        {
            max.push(c);
            p[c]--;
        }
    }
    
    if (max.empty())
        return "-1";
    if (max.top() == '0')
        return "0";
    
    int length = X.length() < Y.length() ? X.length() : Y.length();
    for (int i = 0; i < length; i++)
    {
        if (max.empty())
            break;
        answer += max.top();
        max.pop();
    }
    return answer;
}