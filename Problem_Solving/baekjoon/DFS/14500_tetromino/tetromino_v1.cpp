#include <iostream>
#include <vector>
#include <stack>

bool isValid(std::vector<std::vector<int>> &grid,
             std::vector<std::vector<bool>> &visited,
             int &n, int &m, int &row, int &col, int &sum, int &length)
{
    // 2d grid 범위 밖
    if (col < 0 || row < 0 || row >= n || col >= m)
        return false;

    // 이미 방문 했던 곳
    if (length == 4 || visited[row][col])
    {
        length--;
        sum -= grid[row][col];
        visited[row][col] = false;
        return false;
    }

    return true;
}

int dfsShape(std::vector<std::vector<int>> &grid,
             std::vector<std::vector<bool>> &visited,
             int &n, int &m, int row, int col)
{
    // 다음 방향을 가리키는 값들 (현재 위치의 상하좌우)
    std::vector<int> dRow = {0, 1, 0, -1};
    std::vector<int> dCol = {-1, 0, 1, 0};

    // 좌표값
    std::stack<std::pair<int, int>> stack;
    // 현재 위치
    stack.push(std::make_pair(row, col));
    int sum = 0;
    int max = 0;
    int length = 0;
    while (!stack.empty())
    {
        // 현재 위치가 범위 밖이든 안에 있던 상관하지 않고 일단 stack에서 뽑아준다.
        std::pair<int, int> current = stack.top();
        stack.pop();
        row = current.first;
        col = current.second;

        // stack에 넣은 값들 중 갈 수 있는 곳과 갈 수 없는 곳을 구분해준다.
        if (!isValid(grid, visited, n, m, row, col, sum, length))
            continue;

        // 현재위치 방문한 것으로 체크
        visited[row][col] = true;
        // 현재 위치 방문했으면 더해준다.
        sum += grid[row][col];
        length++;

        if (length == 4)
        {
            max = std::max(max, sum);
            continue;
        }

        // 현제위치에서 상하좌우 위치값을 stack에 넣어준다.
        for (int i = 0; i < 4; i++)
        {
            int adjx = col + dCol[i];
            int adjy = row + dRow[i];
            stack.push({adjy, adjx});
        }
    }
    return max;
}

int otherShape(std::vector<std::vector<int>> &grid,
               int &n, int &m, int &row, int &col)
{
    int sum = 0;
    // ㅗ
    if (row - 1 >= 0 && col + 2 < m)
    {
        sum = std::max(sum, grid[row][col] + grid[row][col + 1] + grid[row][col + 2] + grid[row - 1][col + 1]);
    }
    // ㅏ
    if (row + 2 < n && col + 1 < m)
    {
        sum = std::max(sum, grid[row][col] + grid[row + 1][col] + grid[row + 2][col] + grid[row + 1][col + 1]);
    }
    // ㅜ
    if (row + 1 < n && col + 2 < m)
    {
        sum = std::max(sum, grid[row][col] + grid[row][col + 1] + grid[row][col + 2] + grid[row + 1][col + 1]);
    }
    // ㅓ
    if (row + 2 < n && col - 1 >= 0)
    {
        sum = std::max(sum, grid[row][col] + grid[row + 1][col] + grid[row + 2][col] + grid[row + 1][col - 1]);
    }
    return sum;
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

    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // std::vector<std::vector<bool>> tempVisted = visited;
            maxSum = std::max(maxSum, dfsShape(grid, visited, n, m, i, j));
            maxSum = std::max(maxSum, otherShape(grid, n, m, i, j));
        }
    }

    std::cout << maxSum;
    return 0;
}