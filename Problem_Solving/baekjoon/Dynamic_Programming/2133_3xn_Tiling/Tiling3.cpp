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

	// n이 홀수인 경우 2x1, 1x2 타일로 채울 수 없다.
	if (n % 2)
	{
		std::cout << 0;
		return 0;
	}

	std::vector<int> dp;
	dp.push_back(1);
	dp.push_back(0);
	dp.push_back(3);
	dp.push_back(0);

	for (int i = 4; i <= n; i++)
	{
		if (i % 2)
		{
			dp.push_back(0);
			continue;
		}
		// 3x2 타일로 채운뒤 나머지 3x(i - 2) 채우기
		dp.push_back(dp[2] * dp[i - 2]);
		for (int j = 4; j <= i; j += 2)
			// n이 4 이상일 떄 부터 각 타일의 길이만큼 배치할 수 있는 2가지 추가적인 경우가 있따.
			// 각 타일별로 * 2개씩 하다 j == i일 때 0은 1이기에 각 타일의 길이만큼 배치할 수 있는 2가지가 마지막에 추가된다.
			dp[i] = dp[i] + dp[i - j] * 2;
	}

	std::cout << dp[n];

	return 0;
}