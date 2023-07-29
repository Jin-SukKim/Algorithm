#include <iostream>
#include <vector>
#include <climits>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> rgb(n + 1, std::vector<int>(3));

	int minCost = INT_MAX;

	for (int i = 1; i <= n; i++)
		std::cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

	for (int colors = 0; colors < 3; colors++)
	{
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3));
		dp[1][colors] = rgb[1][colors];
		// 2번째 집은 첫 번째 집과 색이 같으면 안되므로 최대값으로 설정해
		// 2번째 집 계산 시 무시될 수 있도록 해준다.
		// 하지만 INT_MAX로 설정하면 2번째 값이 int의 범위를 초과하므로 임의의 숫자로 지정해준다.
		dp[1][(colors + 1) % 3] = dp[1][(colors + 2) % 3] = INT_MAX - 10000;

		// 2번째 집과 맨 마지막인 N번째 집만 1번째 집의 색과 다르면 된다.
		for (int i = 2; i <= n; i++)
		{
			dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
			dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
			dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		}

		minCost = std::min(minCost, std::min(dp[n][(colors + 1) % 3], dp[n][(colors + 2) % 3]));
	}

	std::cout << minCost;
	return 0;
}