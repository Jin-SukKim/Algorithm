#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int fixLine(std::string& s, std::vector<char> &pattern, int j)
{
	int count = 0;
	for (int m = j; m < j + 8; m++)
	{
		if (s[m] != pattern[m % 2])
			count++;
	}
	return count;
}

int countBoard(std::vector<std::string>& board, int i, int j)
{
	int countW = 0, countB = 0;
	std::vector<char> WB = {'W', 'B'};
	std::vector<char> BW = {'B', 'W'};
	for (int n = i; n < i + 8; n++)
	{
		countW += fixLine(board[n], n % 2 ? WB : BW, j);
		countB += fixLine(board[n], n % 2 ? BW : WB, j);
	}

	return std::min(countW, countB);
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> board(n);
	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		board[i] = s;
	}

	int res = INT_MAX;

	for (int i = 0; i + 8 <= n; i++)
	{
		for (int j = 0; j + 8 <= m; j++)
		{
			res = std::min(res, countBoard(board, i ,j));
		}
	}

	std::cout << res;
	return 0;
}