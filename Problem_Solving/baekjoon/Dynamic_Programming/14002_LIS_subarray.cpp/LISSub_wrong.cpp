#include <iostream>
#include <vector>
#include <algorithm>

// 70% 정도에서 실패했다.
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
			auto index = std::lower_bound(sub.begin(), sub.end(), nums[i]);
			*index = nums[i];
			dp.push_back(index - sub.begin() + 1);
		}
	}

	std::cout << sub.size() << "\n";
	for (int& i : sub)
		std::cout << i << " ";
	return 0;
}