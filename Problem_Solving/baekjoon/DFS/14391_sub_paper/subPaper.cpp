#include <iostream>
#include <vector>
#include <string>

// 가로는 direction에 true로 되어있고 세로는 false로 되어있다.
int sum(std::vector<std::vector<int>> &paper, std::vector<std::vector<bool>> &direction,
        int &N, int &M, int row, int column)
{
    int totalSum = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            // 가로 연속
            if (direction[i][j])
            {
                sum = sum * 10 + paper[i][j];
            }
            // 끊기면 전체 합에 추가
            else
            {
                totalSum += sum;
                sum = 0;
            }
        }
        totalSum += sum;
    }

    for (int j = 0; j < M; j++)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            // 세로 연속
            if (!direction[i][j])
            {
                sum = sum * 10 + paper[i][j];
            }
            // 끊기면 전체 합에 추가
            else
            {
                totalSum += sum;
                sum = 0;
            }
        }
        totalSum += sum;
    }
    return totalSum;
}

void dfs(std::vector<std::vector<int>> &paper, std::vector<std::vector<bool>> &direction,
         int &N, int &M, int row, int column, int& maxSum)
{
    if (row == N)
    {
        maxSum = std::max(maxSum, sum(paper, direction, N, M, row, column));
        return;
    }

    // 가로 끝에 도달했으면 row + 1한뒤 column은 처음부터 다시 돌아간다.
    if (column == M)
    {
        dfs(paper, direction, N, M, row + 1, 0, maxSum);
        return;
    }

    // 어떤 칸을 탐색할 때 해당 칸을 가로로 사용할지, 세로로 사용할지 교려한다.
    // 현재 칸을 가로로 사용
    direction[row][column] = true;
    dfs(paper, direction, N, M, row, column + 1, maxSum);
    // 현재 칸을 세로로 사용
    direction[row][column] = false;
    dfs(paper, direction, N, M, row, column + 1, maxSum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> paper(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < M; j++)
            paper[i][j] = s[j] - '0';
    }

    int max = 0;
    std::vector<std::vector<bool>> direction(N, std::vector<bool>(M, false));
    dfs(paper, direction, N, M, 0, 0, max);
    std::cout << max;

    return 0;
}