#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

struct info
{
    int col;
    int row;
    int bridge;
};

void dfs(std::vector<std::vector<int>> &graph, std::vector<std::vector<bool>> &visitied,
         int &N, int &island, int col, int row)
{
    // 갈 수 있는 방향
    int dirCol[4] = {0, 0, -1, 1};
    int dirRow[4] = {-1, 1, 0, 0};

    std::stack<std::pair<int, int>> s;
    s.push(std::make_pair(col, row));

    while (!s.empty())
    {
        auto t = s.top();
        s.pop();

        col = t.first;
        row = t.second;

        // 그래프 범위 밖이거나 바다이거나 섬인데 방문했었다면
        if (col < 0 || col >= N || row < 0 || row >= N ||
            !graph[col][row] || visitied[col][row])
            continue;

        visitied[col][row] = true;
        graph[col][row] = island;

        for (int i = 0; i < 4; i++)
        {
            int nCol = col + dirCol[i];
            int nRow = row + dirRow[i];
            s.push({nCol, nRow});
        }
    }
}

void bfs(std::vector<std::vector<int>> &graph, std::vector<std::vector<bool>> visitied,
         int &bridge, int &N, int col, int row)
{
    // 갈 수 있는 방향
    int dirCol[4] = {0, 0, -1, 1};
    int dirRow[4] = {-1, 1, 0, 0};

    std::queue<info> q;
    q.push({col, row, 0});

    int island = graph[col][row];
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        col = f.col;
        row = f.row;

        if (!graph[col][row])
            bridge++;

        for (int i = 0; i < 4; i++)
        {
            int nCol = col + dirCol[i];
            int nRow = row + dirRow[i];

            // 그래프 범위 밖이거나 같은 섬이거나 바다인데 방문했다면
            if (nCol < 0 || nCol >= N || nRow < 0 || nRow >= N ||
                visitied[nCol][nRow] || graph[nCol][nRow] == island)
                continue;

            // 다리를 이어서 다른 섬에 도착했다면
            if (graph[nCol][nRow] && graph[nCol][nRow] != island) {
                bridge = f.bridge;
                return;
            }
                
            q.push({nCol, nRow, f.bridge + 1});
            visitied[nCol][nRow] = true;
        }
    }
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
        for (int j = 0; j < N; j++)
        {
            std::cin >> graph[i][j];
        }
    }
    std::vector<std::vector<bool>> visitied(N, std::vector<bool>(N, false));

    int islands = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 방문안해봤거나 섬이라면
            if (!visitied[i][j] && graph[i][j])
            {
                dfs(graph, visitied, N, islands, i, j);
                islands++;
            }
        }
    }

    // 초기화
    for (int i = 0; i < N; i++)
        std::fill(visitied[i].begin(), visitied[i].end(), false);
    int minBridge = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j])
            {
                int bridge = 0;
                bfs(graph, visitied, bridge, N, i, j);
                if (bridge)
                    minBridge = std::min(minBridge, bridge);
            }
        }
    }

    std::cout << minBridge;
    return 0;
}