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

	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	// 아무것도 빼지 않는 경우와 수 하나를 뺀 경우
	std::vector<std::vector<int>> dp(2, std::vector<int>(n));
	int max = dp[0][0] = dp[1][0] = nums[0];

	for (int i = 1; i < n; i++)
	{
		// 수를 제거하지 않는 경우
		dp[0][i] = std::max(nums[i], dp[0][i - 1] + nums[i]);
		// 수를 제거하는 경우
		// 만약 수를 더해줬는데 이전 값보다 작아졌다면 이전 dp값을 가져와
		// 현재 수를 제외해준다.
		dp[1][i] = std::max(dp[0][i - 1], dp[1][i - 1] + nums[i]);
		
		max = std::max(max, std::max(dp[0][i], dp[1][i]));
	}

	std::cout << max;
	return 0;
}