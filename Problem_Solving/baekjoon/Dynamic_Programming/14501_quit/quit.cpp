#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> weeks(N + 1);
    for (int i = 0; i < N; i++)
    {
        int t, p;
        std::cin >> t >> p;
        weeks[i] = std::make_pair(t, p);
    }
    std::vector<int> dp(N + 1);

    int maxProfit = 0;
    for (int i = 0; i <= N; i++)
    {
        dp[i] = std::max(maxProfit, dp[i]);
        if (weeks[i].first + i <= N)
            // i 일에 번 돈과 이전에 번 돈을 비교해 더 큰 값을 저장
            dp[i + weeks[i].first] = std::max(dp[i + weeks[i].first], weeks[i].second + dp[i]);
        maxProfit = std::max(maxProfit, dp[i]);
    }
    std::cout << maxProfit;
    return 0;
}