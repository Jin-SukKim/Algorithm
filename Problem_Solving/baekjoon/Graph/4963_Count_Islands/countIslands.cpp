#include <iostream>
#include <vector>
#include <stack>

void dfs(std::vector<std::vector<int>> &graph,
         int &h, int &w, int row, int col)
{
    // 현재위치에서 갈 상하좌우와 대각선 값
    std::vector<int> dirRow = {0, 1, 0, -1, -1, 1, 1, -1};
    std::vector<int> dirCol = {-1, 0, 1, 0, -1, 1, -1, 1};

    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(row, col));

    int count = 0;
    while (!stack.empty())
    {
        auto top = stack.top();
        stack.pop();

        row = top.first;
        col = top.second;

        // 2d graph 범위 밖이거나 좌표의 값이 0일때
        if (row < 0 || row >= h || col < 0 || col >= w || !graph[row][col])
            continue;

        // 1이었던 부분을 0으로 만들어줘 또 다시 탐색하지 않도록해준다.
        graph[row][col] = 0;

        // 현재 위치에서 일단 상하좌우와 대각선의 좌표를 stack에 넣어준다.
        for (int i = 0; i < 8; i++)
        {
            int nRow = row + dirRow[i];
            int nCol = col + dirCol[i];
            stack.push({nRow, nCol});
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int w, h;
    std::cin >> w >> h;

    std::vector<int> ans;
    while (w && h)
    {
        std::vector<std::vector<int>> graph(h, std::vector<int>(w));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                std::cin >> graph[i][j];
            }
        }

        int count = 0;
        // 그래프에서 0은 지나치고 1을 만나면 탐색을 시작
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                // 1인 섬의 부분을 찾으면 검색 시작
                if (graph[i][j])
                {
                    dfs(graph, h, w, i, j);
                    count++;
                }
            }
        }
        ans.push_back(count);

        std::cin >> w >> h;
    }

    for (int &i : ans)
        std::cout << i << '\n';
    return 0;
}