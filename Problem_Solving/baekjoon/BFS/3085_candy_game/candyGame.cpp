#include <iostream>
#include <vector>
#include <string>

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void checkLine(std::vector<std::vector<char>> &board, int &n, int &max)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
                count++;
            else
            {
                if (max < count)
                    max = count;
                count = 1;
            }
        }
        if (max < count)
            max = count;
    }

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (board[j][i] == board[j + 1][i])
                count++;
            else
            {
                if (max < count)
                    max = count;
                count = 1;
            }
        }
        if (max < count)
            max = count;
    }
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
        for (int j = 0; j < n - 1; j++)
        {
            swap(board[i][j], board[i][j + 1]);
            checkLine(board, n, max);
            swap(board[i][j], board[i][j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            swap(board[j][i], board[j + 1][i]);
            checkLine(board, n, max);
            swap(board[j][i], board[j + 1][i]);
        }
    }

    std::cout << max;
    return 0;
}
