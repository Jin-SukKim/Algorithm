#include <vector>
#include <iostream>

int fib(int n) {
    if (n == 0) {
        std::cout << 1 << ' ' << 0 << std::endl;
        return 0;
    }
    std::vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[n - 1] << ' ' << dp[n] << std::endl; 
    return dp[n];
}

int main() 
{
    int n;
    std::cin >> n;

    while (n--)
    {
        int t;
        std::cin >> t;
        fib(t);
    }
    return 0;
}