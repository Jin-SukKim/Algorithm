#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> p;
    
    for (const char& c : s)
    {
        if (c == '(')
            p.push(c);
        else if (c == ')' && !p.empty())
            p.pop();
        else
            return false;
    }
    
    // 모두 올바른 짝이 지어졌으면
    if (p.empty())
        return true;
    
    return false;
}