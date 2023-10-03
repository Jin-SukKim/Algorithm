#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> s;
    int hamburger[4] = {1, 2, 3, 1};
    for (int& i : ingredient)
    {
        s.push(i);
        
        if (i == 1 && s.size() >= 4)
        {
            stack<int> check;
            answer++;
            for (int j = 3; j >= 0; j--)
            {
                int top = s.top();
                if (hamburger[j] == top) {
                    s.pop();
                    
                    check.push(top);
                }
                else {
                    answer--;
                    while (!check.empty())
                    {
                        s.push(check.top());
                        check.pop();
                    }
                    break;
                }
            }
        }
    }
    
    return answer;
}