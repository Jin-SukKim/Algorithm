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

	std::vector<std::vector<int>> pyramid(n);

	for (int i = 1; i <= n; i++)
	{
		std::vector<int> level(i);
		for (int j = 0; j < i; j++)
		{
			std::cin >> level[j];
		}
		pyramid[i - 1] = level;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			// 아래층에 있는 수는 위 층의 대각선 왼쪽 또는 오른쪽에 있다.
			if (j == 0)
				pyramid[i][j] += pyramid[i - 1][j];
			else if (j == i)
				pyramid[i][j] += pyramid[i - 1][j - 1];
			else
				pyramid[i][j] = std::max(pyramid[i - 1][j - 1] + pyramid[i][j],
										 pyramid[i - 1][j] + pyramid[i][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
		max = std::max(pyramid[n - 1][i], max);

	std::cout << max;
	return 0;
}