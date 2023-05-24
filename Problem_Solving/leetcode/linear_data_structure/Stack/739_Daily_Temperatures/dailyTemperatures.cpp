/*
    739. Daily Temperatures
        Given an array of integers temperatures represents the daily temperatures,
        return an array answer such that answer[i] is the number of days you have to wait
        after the ith day to get a warmer temperature.
        If there is no future day for which this is possible, keep answer[i] == 0 instead.

    Example 1:
        Input: temperatures = [73,74,75,71,69,72,76,73]
        Output: [1,1,4,2,1,1,0,0]
        Example 2:

        Input: temperatures = [30,40,50,60]
        Output: [1,1,1,0]
        Example 3:

        Input: temperatures = [30,60,90]
        Output: [1,1,0]

    Constraints:
        - 1 <= temperatures.length <= 105
        - 30 <= temperatures[i] <= 100
*/
#include <vector>
#include <stack>
#include <algorithm>

// average time and space complexity
std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
{
    // 전부 0으로 초기화
    std::vector<int> ans(temperatures.size(), 0);
    std::stack<int> s;
    enum class t { temperatures };

    auto begin = temperatures.begin();
    for (int i = 0; i < ans.size(); i++)
    {   
        while (s.size() && (temperatures[i] > temperatures[s.top()]))
        {   
            int& last = s.top();
            s.pop();
            ans[last] = i - last;
        }

        s.push(i);
    }

    return ans;
}

int main() {
    std::vector<int> t = {73,74,75,71,69,72,76,73};
    dailyTemperatures(t);
    return 0;
}