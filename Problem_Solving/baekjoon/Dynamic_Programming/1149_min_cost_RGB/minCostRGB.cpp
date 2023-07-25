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

	// 최소 비용을 계속 더해가면서 채워나간다.
	std::vector<std::vector<int>> house(n+1, std::vector<int>(3));

	for (int i = 1; i <= n; i++)
	{
		std::vector<int> rgb(3);
		std::cin >> rgb[0] >> rgb[1] >> rgb[2];

		// i집을 빨간집으로 색칠했을 때 이전 집은 초록색이나 파란색이어야 된다.
		house[i][0] = std::min(house[i-1][1], house[i-1][2]) + rgb[0];
		// i집을 초록집으로 색칠했을 때 이전 집은 빨간색이나 파란색이어야 된다.
		house[i][1] = std::min(house[i-1][0], house[i-1][2]) + rgb[1];
		// i집을 파란집으로 색칠했을 때 이전 집은 빨간색이나 초록색이어야 된다.
		house[i][2] = std::min(house[i-1][0], house[i-1][1]) + rgb[2];
	}

	// 각기 다른 색으로 색칠을 시작한 값들 중 최소비용을 찾아준다.
	int cost = std::min(house[n][2], std::min(house[n][0], house[n][1]));
	std::cout << cost;
	return 0;
}