#include <iostream>
#include <vector>
#include <stack>

bool isValid(std::vector<std::vector<bool>> &visited,
             int &n, int &m, int &row, int &col)
{
    // 2d grid 범위 밖
    if (col < 0 || row < 0 || col >= n || row >= m)
        return false;

    // 이미 방문 했던 곳
    if (visited[row][col])
        return false;

    return true;
}

int dfsShape(std::vector<std::vector<int>> &grid,
             std::vector<std::vector<bool>> &visited,
             int &n, int &m, int row, int col)
{
    // 다음 방향을 가리키는 값들 (현재 위치의 상하좌우)
    std::vector<int> dRow = {0, 1, 0, -1};
    std::vector<int> dCol = {-1, 0, 1, 0};

    std::stack<std::pair<int, int>> stack;
    // 현재 위치
    stack.push(std::make_pair(row, col));
    visited[row][col] = true;

    int macol = 0;
    while (!stack.empty())
    {
        std::pair<int, int> current = stack.top();
        stack.pop();
        int row = current.first;
        int col = current.second;

        // stack에 넣은 값들 중 갈 수 있는 곳과 갈 수 없는 곳을 구분해준다.
        if (!isValid(visited, n, m, row, col))
            continue;

        // 현재위치 방문한 것으로 체크
        visited[row][col] = true;

        // 현제위치에서 상하좌우 위치값을 stack에 넣어준다. 
        for (int i = 0; i < 4; i++)
        {
            int adjx = col + dCol[i];
            int adjy = row + dRow[i];
            stack.push({adjy, adjx});
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> grid[i][j];

    return 0;
}