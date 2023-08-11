#include <iostream>
#include <vector>
#include <queue>
#include <string>

void dfs(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &visited,
         int &N, int &M, int &startC, int &startR, int col, int row, int depth)
{
    int dirCol[4] = {-1, 1, 0, 0};
    int dirRow[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nCol = col + dirCol[i];
        int nRow = row + dirRow[i];

        if (nCol < 0 || nCol >= N || nRow < 0 || nRow >= M)
            continue;

        // 방문하지 않았고 같은 색이라면
        if (!visited[nCol][nRow] && board[col][row] == board[nCol][nRow])
        {
            visited[nCol][nRow] = true;
            dfs(board, visited, N, M, startC, startR, nCol, nRow, depth + 1);
            visited[nCol][nRow] = false;
        }
        // 최소한 사각형을 만들 수 있는 4의 길이에 시작점으로 도달했다면
        // circle(순환)을 만들었다고 볼 수 있다.
        else if (nCol == startC && nRow == startR && depth > 3)
        {
            std::cout << "Yes";
            exit(0);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> board(N, std::vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = s[j];
        }
    }

    std::vector<std::vector<bool>> vistied(N, std::vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!vistied[i][j])
            {
                vistied[i][j] = true;
                dfs(board, vistied, N, M, i, j, i, j, 1);
            }
        }
    }

    std::cout << "No";
    return 0;
}