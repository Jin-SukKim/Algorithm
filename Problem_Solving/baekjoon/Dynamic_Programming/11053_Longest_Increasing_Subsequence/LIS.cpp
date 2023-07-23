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

	// 부분 수열의 최단 길이는 항상 1이다.
	std::vector<int> dp(n + 1, 1);
	// 최장 증가 부분 수열(LIS) 알고리즘
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// 현재 index의 정수보다 작은 값 중 최장 길이를 찾아 + 1 해준 값이
			// 현재 index의 최장 거리가 된다.
			// ex) 수열 {1, 2, 3, 1, 4} 이고 마지막 숫자인 4의 최장 길이를 구하면
			// 		부분 수열의 최장 길이 배열은 = {1, 2, 3, 1, ?}이고
			// 		정수 4보다 작은 값 중 최장 길이을 가진 3의 길이에 + 1이 4의 최장 거리가 된다.
			if (nums[j] < nums[i])
			{
				dp[i] = std::max(dp[j] + 1, dp[i]); 
			}
		}
	}

	std::cout << *std::max_element(dp.begin(), dp.end());
	return 0;
}