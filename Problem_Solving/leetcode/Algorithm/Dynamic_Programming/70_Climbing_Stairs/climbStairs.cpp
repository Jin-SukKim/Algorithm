/*
    70. Climbing Stairs
        You are climbing a staircase.
        It takes n steps to reach the top.
        Each time you can either climb 1 or 2 steps.
        In how many distinct ways can you climb to the top?

    Example 1:
        Input: n = 2
        Output: 2
        Explanation: There are two ways to climb to the top.
        1. 1 step + 1 step
        2. 2 steps

    Example 2:
        Input: n = 3
        Output: 3
        Explanation: There are three ways to climb to the top.
        1. 1 step + 1 step + 1 step
        2. 1 step + 2 steps
        3. 2 steps + 1 step

    Constraints:
        1 <= n <= 45
*/
#include <vector>
// 각각 1계단 또는 2계단씩 오를 수 있다면 정상에 도달하기 위해
// n계단을 올라야 하는 경로의 수
class Solution
{
public:
    // 기본적으로 피보나치 수와 동일한 유형의 문제다
    // 피보나치는 0과 1을 return하지만 이건 1과 2를 return하면 된다.

    // time limit exceed
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    int climbStairs1(int n)
    {
        std::vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // 메모이제이션
    std::vector<int> dp;
    int climbStairs2(int n)
    {
        if (dp.empty())
            dp = std::vector<int>(n+1, 0);
        if (n <= 2)
            return n;

        if (dp[n])
            return dp[n];
            
        dp[n] = climbStairs2(n - 1) + climbStairs2(n - 2);
        return dp[n];
    }
};