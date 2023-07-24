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

	// 맨처음 3까지의 값 설정
	std::vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		// i는 1^2를 i개 더하면 구할 수 있다.
		dp[i] = i;
		// 1^2부터 시작해 2^2, 3^2 등으로 시작하는 경우 확인해서 최소한의 항의 개수 구하기
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = std::min(dp[i], dp[i - j * j] + 1);
		}
	}
	std::cout << dp[n];
	return 0;
}