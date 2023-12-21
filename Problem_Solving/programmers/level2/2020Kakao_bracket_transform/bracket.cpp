#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// 올바른 괄호 문자열인지 확인
bool check(string& bracket) {
    stack<char> s;
    for (char& c : bracket) {
        if (c == '(')
            s.push(c);
        else if (!s.empty()) 
            s.pop();
        else
            return false;
    }
    
    return s.empty();
}

string solution(string p) {
    // 1단계 : 빈 문자열
    if (p.empty())
        return "";
    
    // 2단계 : 균형잡힌 괄호 문자열('('과 ')'의 개수가 같다면), u, v로 분리
    int l = 0, r = 0; // l = '(', r = ')'의 개수
    for (char& c : p) {
        if (c == '(')
            l++;
        else
            r++;
        
        // 균형잡힌 괄호 문자열
        if (l == r)
            break;
    }
    // u, v로 분리 (u = 균형잡힌 괄호 문자열로 더 이상 분리할 수 없어야되고, v는 빈 문자열 가능)
    string u = p.substr(0, l + r);
    string v = p.substr(l + r);
    
    string answer = "";
    // 3단계 : u가 올바른 괄호 문자열 이라면 v에 대해 1단계부터 다시 수행
    if (check(u))
        answer = u + solution(v); // 그 결과를 u에 붙인 후 반환
    // 아니라면 4단계
    else {
        // 빈 문자열에 '('을 붙인 후 v를 1단계부터 다시 수행 후 ')'를 붙여준다.
        answer = "(" + solution(v) + ")";
        // u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다.
        for (int i = 1; i < u.length() - 1; ++i) 
            answer += u[i] == '(' ? ')' : '(';
    }
    
    return answer;
}