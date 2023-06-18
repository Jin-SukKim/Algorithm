/*
    241. Different Ways to Add Parentheses
        Given a string expression of numbers and operators,
        return all possible results from computing all the different possible
        ways to group numbers and operators.
        You may return the answer in any order.

        The test cases are generated such that the output values fit
        in a 32-bit integer and the number of different results does not
        exceed 104.

    Example 1:
        Input: expression = "2-1-1"
        Output: [0,2]
        Explanation:
        ((2-1)-1) = 0
        (2-(1-1)) = 2

    Example 2:
        Input: expression = "2*3-4*5"
        Output: [-34,-14,-10,-10,10]
        Explanation:
        (2*(3-(4*5))) = -34
        ((2*3)-(4*5)) = -14
        ((2*(3-4))*5) = -10
        (2*((3-4)*5)) = -10
        (((2*3)-4)*5) = 10

    Constraints:
        1 <= expression.length <= 20
        expression consists of digits and the operator '+', '-', and '*'.
        All the integer values in the input expression are in the range [0, 99].
*/
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

// 시간과 메모리 공간 둘다 많이 사용한다.
class Solution
{
public:
    // 분할 정복 이용
    // 복수 개의 계산 결과를 return
    // ex) 3-4*5는 [-17, -5]의 복수 개의 계산 결과를 갖는다.
    std::vector<int> compute(std::vector<int> & left, std::vector<int>& right, char& op)
    {
        std::vector<int> results;
        int compute = 0;
        for (int l : left)
        {
            for(int r : right)
            {
                if (op == '+')
                    compute = l + r;
                else if (op == '-')
                    compute = l - r;
                else if (op == '*')
                    compute = l * r;
                results.push_back(compute);
            }
        }
        return results;
    }
    std::vector<int> diffWaysToCompute(std::string expression)
    {   
        // string이 전부 int인지 확인(그래서 마지막에 한자리 숫자가 아닌 것도 숫자로 인식하게 한다.)
        if (std::all_of(expression.begin(), expression.end(), ::isdigit))
            return {std::stoi(expression)};

        std::vector<int> results;
        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];
            // *, -, + 연산자 등장 시 좌/우 분할을 하고 계산
            if (c == '+' || c == '-' || c == '*')
            {
                std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> right = diffWaysToCompute(expression.substr(i+1));

                // 복수 개의 계산 결과를 result에 합쳐준다.
                std::vector<int> cal = compute(left, right, c);
                std::move(cal.begin(), cal.end(), std::back_inserter(results));
            }
        }

        return results;
    }
};

int main()
{
    std::string s = "2-1-1";
    Solution sol;
    sol.diffWaysToCompute(s);
    return 0;
}