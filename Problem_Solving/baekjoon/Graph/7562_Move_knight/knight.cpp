#include <iostream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>> &board,
         int &n, int &startC, int &startR, int &tC, int &tR)
{
    // 나이트 말이 움직일 수 있는 다음 칸
    std::vector<int> dirCol = {-2, -2, -1, -1, 1, 1, 2, 2};
    std::vector<int> dirRow = {1, -1, 2, -2, 2, -2, 1, -1};

    std::queue<std::pair<int, int>> q;
    q.push({startC, startR});

    while (!q.empty())
    {
        int col = q.front().first;
        int row = q.front().second;

        q.pop();

        // 목표 지점에 도달했다면
        if (col == tC && row == tR)
        {
            std::cout << board[col][row] - 1 << '\n';
            return;
        }

        for (int i = 0; i < 8; i++)
        {
            // 움직일 수 있는 다음 위치
            int nCol = col + dirCol[i];
            int nRow = row + dirRow[i];

            // 보드 안이어야 하고 아직 안 가본 곳이어야 한다.
            // 처음 가는 곳은 0 이 입력되어 있고 아니라면 0보다 큰 값이 있다.
            if (nCol >= 0 && nCol < n && nRow >= 0 && nRow < n && !board[nCol][nRow])
            {
                board[nCol][nRow] = board[col][row] + 1;
                q.push({nCol, nRow});
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
    {
        int n;
        std::cin >> n;

        // 보드 생성
        std::vector<std::vector<int>> board(n, std::vector<int>(n));

        int startCol, startRow;
        std::cin >> startCol >> startRow;
        // 출발 위치
        board[startCol][startRow] = 1;

        // 목표 위치
        int targetCol, targetRow;
        std::cin >> targetCol >> targetRow;

        bfs(board, n, startCol, startRow, targetCol, targetRow);
    }

    return 0;
}