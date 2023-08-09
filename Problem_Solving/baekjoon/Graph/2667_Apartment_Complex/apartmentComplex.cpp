#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &ans,
         int &N, int row, int col)
{
    // 현재위치에서 갈 상하좌우 값
    std::vector<int> dirRow = {0, 1, 0, -1};
    std::vector<int> dirCol = {-1, 0, 1, 0};

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
        if (row < 0 || row >= N || col < 0 || col >= N || !graph[row][col])
            continue;

        // 1이었던 부분을 0으로 만들어줘 또 다시 탐색하지 않도록해준다.
        count++;
        graph[row][col] = 0;

        // 현재 위치에서 일단 상하좌우의 좌표를 stack에 넣어준다.
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dirRow[i];
            int nCol = col + dirCol[i];
            stack.push({nRow, nCol});
        }
    }
    
    if (count)
        ans.push_back(count);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> graph(N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    std::vector<int> ans;
    // 그래프에서 0은 지나치고 1을 만나면 탐색을 시작
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dfs(graph, ans, N, i, j);
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (int& i : ans)
        std::cout << i << '\n';
    return 0;
}