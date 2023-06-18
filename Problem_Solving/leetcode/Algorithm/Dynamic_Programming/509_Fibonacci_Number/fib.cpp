/*
    509. Fibonacci Number
        The Fibonacci numbers, commonly denoted F(n) form a sequence, 
        called the Fibonacci sequence, such that each number is the sum of 
        the two preceding ones, starting from 0 and 1. 
        That is,
            F(0) = 0, F(1) = 1
            F(n) = F(n - 1) + F(n - 2), for n > 1.
            Given n, calculate F(n).

    Example 1:
        Input: n = 2
        Output: 1
        Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
    
    Example 2:
        Input: n = 3
        Output: 2
        Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
    
    Example 3:
        Input: n = 4
        Output: 3
        Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
    
    Constraints:
        0 <= n <= 30
*/
#include <vector>

class Solution {
public:
    // Tabulation(다이나믹 프로그래밍 상향식)
    int fib(int n)
    {
        std::vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // 공간 절약한 Tabulation (다이나믹 프로그래밍 상향식)
    int fib1(int n) {
       int prev1 = 0, prev2 = 1;
       while (n--)
       {
            int cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
       } 
       return prev1;
    }

    // Memoization (다이나믹 프로그래밍 하향식)
    std::vector<int> f;
    int fib2(int n)
    {        
        if (f.empty())
            f = std::vector<int>(n + 1, 0);

        if (n <= 1)
            return n;

        if (f[n])
            return f[n];
        
        f[n] = fib2(n - 1) + fib2(n - 2);
        return f[n];
    }    
};