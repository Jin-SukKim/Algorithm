#include <iostream>
#include <vector>
#include <algorithm>
// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(n + 1, 1));

	for (int i = 2; i <= k; i++)
	{
		// [k][n]인 2d array일 때 현재 index의 위의 값과 왼쪽 값
		// 즉, 대각선 값을 더해주면 현재의 개수가 나온다.
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	std::cout << dp[k][n];
	return 0;
}