#include <iostream>
#include <vector>
#include <algorithm>
// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;

	while (t--)
	{
		int n;
		std::cin >> n;

		std::vector<std::vector<int>> sticker(2, std::vector<int>(n));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				std::cin >> sticker[i][j];
		}

		sticker[0][1] += sticker[1][0];
		sticker[1][1] += sticker[0][0];
		for (int i = 2; i < n; i++)
		{
			sticker[0][i] += std::max(sticker[1][i - 1], sticker[1][i - 2]);
			sticker[1][i] += std::max(sticker[0][i - 1], sticker[0][i - 2]);
		}
		
		int max = std::max(sticker[0][n - 1], sticker[1][n-1]);
		std::cout << max << '\n';
	}


	return 0;
}