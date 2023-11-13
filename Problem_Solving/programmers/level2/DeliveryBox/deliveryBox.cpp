#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> sub;
    
    int i = 1;
    for (const int& b : order)
    {
        // 만약 현재보다 뒤에있는 박스가 먼저 실려야할 때 보조 벨트에 넣는다.
        while (i < b)
                sub.push(i++);
        
        // 보조 벨트에 있는 상자를 꺼내야한다면
        if (i > b && !sub.empty())
        {
            if (b == sub.top())
            {
                answer++;
                sub.pop();
            } else
                break;
        }
        
        // 순서가 맞을 때
        else if (i++ == b)
            answer++;
    }
    
    
    return answer;
}