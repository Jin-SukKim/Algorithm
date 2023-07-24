#include <iostream>
#include <vector>
#include <algorithm>
// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;

	while (t--)
	{
		int n;
		std::cin >> n;

		// 최소한 index 4까지 보장
		std::vector<long long> dp(n + 3);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}	

		std::cout << dp[n] << "\n";
	}
	return 0;
}