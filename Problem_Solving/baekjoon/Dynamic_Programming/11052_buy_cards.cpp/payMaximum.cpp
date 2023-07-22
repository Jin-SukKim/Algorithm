#include <iostream>
#include <vector>
#include <algorithm>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	// 카드 i개 포함된 카드팩의 가격 Pi (0개는 0원)
	std::vector<int> cards(n+1);
	for (int i = 1; i <= n; i++)
	{
		// 각 i 개의 카드가 포함된 카드팩의 가격
		std::cin >> cards[i];
	}

	// 각 i개의 카드를 구매할 때 지불해야 되는 최대값
	// 즉 1개 카드 살 때 지불할 최대값은 dp[1]에 저장하고 2개 살 때 최대값을 dp[2] 등등
	// 이어서 저장해준다.
	// 카드가 각 i개 들어있는 카드팩을 사는 걸 기본으로 두고 다른 경우의 수를 비교한다.
	std::vector<int> dp = cards;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// i개의 카드가 포함된 카드팩과 
			// 1 ~ i-1개의 카드가 포함된 카드팩(j) 가격 + i - j개의 카드를 살때
			// 지불한 최대 값을 비교해 최대값을 지불한다.
			dp[i] = std::max(dp[i], cards[j] + dp[i - j]);
		}
	}

	std::cout << dp[n];

	return 0;
}