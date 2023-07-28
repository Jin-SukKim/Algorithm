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

	std::vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++)
	{
		std::cin >> nums[i];
	}

	std::vector<int> dp = nums;

	// 최장 증가 부분 수열(LIS) 알고리즘
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = std::max(dp[i], dp[j] + nums[i]);
			}
		}
	}

	std::cout << *std::max_element(dp.begin(), dp.end());
	return 0;
}