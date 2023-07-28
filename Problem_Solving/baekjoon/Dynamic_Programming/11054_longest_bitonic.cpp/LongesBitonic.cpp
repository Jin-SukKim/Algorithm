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

	std::vector<int> leftDP(n + 1, 1);

	// 최장 바이토닉 부분 수열 알고리즘
	for (int i = 1; i <= n; i++)
	{
        // 왼쪽 부분 배열
        for (int j = 1; j < i; j++)
        {
            if (nums[j] < nums[i])
			{
				leftDP[i] = std::max(leftDP[i], leftDP[j] + 1);
			}
        }
	}
	
	std::vector<int> rightDP(n + 1, 1);
	// 최장 바이토닉 부분 수열 알고리즘
	for (int i = n; i > 0; i--)
	{
        // 오른쪽 부분 배열
        for (int j = n; j > i; j--)
        {
            if (nums[j] < nums[i])
			{
				rightDP[i] = std::max(rightDP[i], rightDP[j] + 1);
			}
        }
	}
	
	int max = 0;

	for (int i = 1; i <= n; i++)
		max = std::max(max, leftDP[i] + rightDP[i]);

	std::cout << max-1;
	return 0;
}