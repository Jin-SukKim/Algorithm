#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int h = 0; h < s.length(); h++) {
        stack<char> brck;
        if (s[0] == '[' || s[0] == '{' || s[0] == '(') {
            for (int i = 0; i < s.length(); i++) {
                // 스택이 비었으면 바로 push
                if (brck.empty()) 
                    brck.push(s[i]);  
                // {, [, ( 와 }, ], )가 서로 매칭이 된다면 스택에서 pop해주기
                else if (brck.top() == '{' && s[i] == '}') 
                    brck.pop();
                else if (brck.top() == '[' && s[i] == ']') 
                    brck.pop();
                else if (brck.top() == '(' && s[i] == ')') 
                    brck.pop();
                //만약 아무것도 매칭되지 않으면 바로 push
                else  
                    brck.push(s[i]);
                
                if (i == s.length() - 1 && brck.empty()) 
                        answer++;
            }
        }
        
        // 회전
        s.push_back(s[0]);
        s.erase(0, 1);
    }
    
    return answer;
}