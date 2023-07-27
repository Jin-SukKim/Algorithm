#include <iostream>
#include <vector>
#include <algorithm>
// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> wine(n + 2, 0);

	for (int i = 1; i <= n; i++)
		std::cin >> wine[i];

	std::vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		// n번째를 안마실때 앞의 두 잔을 마신다.
		// n번째를 마시면 바로 앞의 잔을 안마시거나 한 잔 건너뛰어 i - 2번째 잔을
		// 마시지 않는다.
		dp[i] = std::max(dp[i - 1], std::max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]));
	}

	std::cout << dp[n];
	return 0;
}