#include <iostream>
#include <vector>
// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	// 아무것도 없어도 1개의 경우다
	std::vector<int> dp(n+1, 1);
	dp[1] = 3;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}

	std::cout << dp[n];
	return 0;
}