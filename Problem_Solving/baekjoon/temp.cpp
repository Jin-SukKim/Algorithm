#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> weeks(N);
    for (int i = 0; i < N; i++)
    {
        int t, p;
        std::cin >> t >> p;
        weeks[i] = std::make_pair(t, p);
    }

    int maxProfit = 0;
    for (int i = 0; i < N; i++)
    {
        int term = weeks[i].first - 1;
        int profit = weeks[i].second;
        for (int j = i + 1; j < N; j++)
        {
            if (term == 0 && weeks[j].first <= N - j)
            {
                term = weeks[j].first - 1;
                profit += weeks[j].second;
            }
            else
                term--;
        }
        maxProfit = maxProfit < profit ? profit : maxProfit;
    }
    std::cout << maxProfit;
    return 0;
}