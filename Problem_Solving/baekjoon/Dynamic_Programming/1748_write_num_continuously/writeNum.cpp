#include <iostream>
#include <cmath>
#include <vector>

int length(int n)
{
    int len = 1;
    while (n /= 10)
    {
        len++;
    }

    return len;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    if (n < 10)
    {
        std::cout << n;
        return 0;
    }

    int len = length(n);
    std::vector<int> dp(len + 1);
    dp[1] = 9;
    dp[2] = 10 * 9 * 2 + 9;

    int max = 99;
    for (int i = 3; i <= len; i++)
    {
        dp[i] = ((dp[i - 1] - dp[i - 2]) / (i - 1)) * 10 * i + dp[i - 1];
        max = max * 10 + 9;
    }

    int min = (max - n) * len;
    std::cout << dp[len] - ((max - n) * len);
    return 0;
}