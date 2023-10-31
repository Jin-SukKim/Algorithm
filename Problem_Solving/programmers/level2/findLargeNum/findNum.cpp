#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    stack<int> s;
    
    for (int i = numbers.size() - 1; i > -1; i--)
    {
        while (!s.empty() && s.top() <= numbers[i])
            s.pop();
        
        if (!s.empty())
            answer[i] = s.top();
        
        s.push(numbers[i]);
    }
    
    return answer;
}