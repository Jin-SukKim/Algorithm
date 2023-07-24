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
		std::cin >> nums[i];

	std::vector<int> dp(n);
	dp[0] = nums[0];
	
	int max = nums[0];
	for (int i = 1; i < n; i++)
	{
		// 부분 배열의 합이 현재 값보다 작다면 굳이 더해줄 필요가 없어 숫자를 재시작한다.
		if (dp[i - 1] + nums[i] < nums[i])
			dp[i] = nums[i];
		else
			dp[i] = dp[i - 1] + nums[i];
	}

	std::cout << *std::max_element(dp.begin(), dp.end());
	return 0;
}