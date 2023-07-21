#include <iostream>
#include <vector>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> dp;
	dp.push_back(0); // 2 x 0은 0
	dp.push_back(1); // 2 x 1은 1개
	dp.push_back(3); // 2 x 2는 3개

	// 그 이상의 2 x n은 dp[i] = dp[i - 1] + dp[i - 2] * 2의 방법의 수가 필요하다.
	for (int i = 3; i <= n; i++)
	{
		// 하지만 10007로 나눈 나머지값이 필요하다.
		dp.push_back((dp[i - 1] + dp[i - 2] * 2) % 10007);
	}

	std::cout << dp[n];

	return 0;
}