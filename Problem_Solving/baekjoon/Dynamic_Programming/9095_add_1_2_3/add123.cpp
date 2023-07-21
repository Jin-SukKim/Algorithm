#include <iostream>
#include <vector>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--)
	{

		int n;
		std::cin >> n;
		std::vector<int> dp;
		dp.push_back(1); // 1
		dp.push_back(1); // 1은 1개의 방법
		dp.push_back(2); // 2는 2개의 방법
		// 그 이상의 2 x n은 dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]의 방법의 수가 필요하다.
		for (int i = 3; i <= n; i++)
		{
			dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
		}

		std::cout << dp[n] << '\n';
	}

	return 0;
}