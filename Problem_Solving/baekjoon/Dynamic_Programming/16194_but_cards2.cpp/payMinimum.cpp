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

	// 각 i개의 카드를 구매할 때 지불해야 되는 최소값
	// 즉 1개 카드 살 때 지불할 최소값은 dp[1]에 저장하고 2개 살 때 최소값을 dp[2] 등등
	// 이어서 저장해준다.
	std::vector<int> dp = cards;
	dp[0] = cards[1]; // 카드 0개를 사는 경우는 없으므로 계산의 편의성을 위해 0을 1개 샀을 때의 최소값으로 설정해준다.
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			// i개의 카드가 포함된 카드팩과 
			// 1 ~ i-1개의 카드가 포함된 카드팩(j) 가격 + i - j개의 카드를 살때
			// 지불한 최소 값을 비교해 최소값을 지불한다.
			dp[i] = std::min(dp[i], cards[j] + dp[i - j]);
		}
	}

	std::cout << dp[n];

	return 0;
}