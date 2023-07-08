#include <iostream>
#include <vector>
int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<std::vector<bool>> board(100, std::vector<bool>(100, 0));
    int size = 0;

    int n;
    std::cin >> n;

    while (n--)
    {
        int x, y;
        std::cin >> x >> y;
        for (int i = y; i < y + 10; i++)
        {
            for (int j = x; j < x + 10; j++)
            {
                if (!board[i][j]){
                    board[i][j] = 1;
                    size++;
                }
            }
        }
    }

    std::cout << size;

    return 0;
}
