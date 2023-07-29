#include <iostream>
#include <vector>
#include <string>

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

int checkLine(std::vector<std::vector<char>> &board, int &n, int &i, int &j)
{
	int max = 0;
	int row = 0;
	char candy = board[i][j];
	for (int k = 0; k < n; k++)
	{
		if (board[k][j] == candy)
			row++;
		else
		{
			max = std::max(max, row);
			row = 0;
		}
	}

	int col = 0;
	for (int k = 0; k < n; k++)
	{
		if (board[i][k] == candy)
			col++;
		else
		{
			max = std::max(max, col);
			col = 0;
		}
	}

	max = std::max(max, std::max(row, col));
	return max;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<char>> board(n, std::vector<char>(n));

	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < n; j++)
			board[i][j] = s[j];
	}

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			max = std::max(max, checkLine(board, n, i, j));

			if (i + 1 < n)
			{
				swap(board[i][j], board[i + 1][j]);
				max = std::max(max, checkLine(board, n, i, j));
				swap(board[i][j], board[i + 1][j]);
			}
			else
			{
				swap(board[i][j], board[i - 1][j]);
				max = std::max(max, checkLine(board, n, i, j));
				swap(board[i][j], board[i - 1][j]);
			}

			if (j + 1 < n)
			{
				swap(board[i][j], board[i][j + 1]);
				max = std::max(max, checkLine(board, n, i, j));
				swap(board[i][j], board[i][j + 1]);
			}
			else 
			{
				swap(board[i][j], board[i][j - 1]);
				max = std::max(max, checkLine(board, n, i, j));
				swap(board[i][j], board[i][j - 1]);
			}
		}
	}

	std::cout << max;
	return 0;
}
