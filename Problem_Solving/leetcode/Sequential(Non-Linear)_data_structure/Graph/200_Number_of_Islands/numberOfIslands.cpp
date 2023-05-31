/*
    200. Number of Islands
        Given an m x n 2D binary grid grid which represents a map of '1's
        (land) and '0's (water), return the number of islands.

        An island is surrounded by water and is formed by
        connecting adjacent lands horizontally or vertically.
        You may assume all four edges of the grid are all surrounded by water.

    Example 1:
        Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        Output: 1
        Example 2:

        Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        Output: 3

    Constraints:
        - m == grid.length
        - n == grid[i].length
        - 1 <= m, n <= 300
        - grid[i][j] is '0' or '1'.
*/
#include <vector>

void dfs(std::vector<std::vector<char>> &grid, int i, int j)
{
    // 육지가 아닌 경우 종료
    // i와 j가 grid 범위 밖이거나 육지('1')가 아닐떄
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() 
        || grid[i][j] != '1')
        return;

    // 방문한 곳은 1이 아닌 값으로 마킹해 다시 계산하는 경우를 방지(가지치기)
    grid[i][j] = '0'; 

    // 동서남북 탐색(재귀 함수)
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(std::vector<std::vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int count = 0;

    // 행렬(Matrix) 입력값인 행(Row), 열(Cols) 단위로 육지를 찾기
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            // 육지('1')을 발견하면 dfs()로 탐색시작
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}
