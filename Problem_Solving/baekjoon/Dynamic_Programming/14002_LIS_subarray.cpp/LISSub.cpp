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
		std::cin >> nums[i];

	std::vector<int> dp;
	dp.push_back(1);
	// 부분 배열
	std::vector<int> sub;
	sub.push_back(nums[1]);

	int subIndex = 0;
	for (int i = 2; i <= n; i++)
	{
		// 더 큰 값이 있다면 추가
		if (sub[subIndex] < nums[i])
		{
			sub.push_back(nums[i]);
			subIndex++;
			dp.push_back(subIndex + 1);
		}
		// 작거나 같다면 (가장 작은 값부터 시작해야 제일 긴 부분 배열을 얻을 수 있다)
		else
		{
			// lower_bound 함수는 현재값을 찾고 그 index를 return한다.
			// 만약 현재값이 없다면 맨 처음 index를 return한다.
			// ex) {1, 2, 5}가 있고 현재 값이 3이라면 5를 3으로 바꿔준다.
			auto index = std::lower_bound(sub.begin(), sub.end(), nums[i]);
			*index = nums[i];
			dp.push_back(index - sub.begin() + 1); // 현재 값의 부분 배열 최장 길이
		}
	}

	int temp = sub.size();

	std::vector<int> ans;
    // dp와 sub은 0에서부터 시작하나 nums은 0을 공백으로 처리하고 1부터 시작한다.
	for (int i = n - 1; i >= 0; i--)
	{
		if (dp[i] == temp)
		{
			ans.push_back(nums[i + 1]);
			temp--;
		}
	}

	std::cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		std::cout << ans[i] << " ";
	}

	return 0;
}