#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

// dfs은 최단거리를 찾기위해 완전 탐색을 하고
// 그중 가장 작은 값을 선택해야 해 경로가 아주 많을 수 있으므로 시간 복잡도가 커진다.
// 시간초과
void dfs(std::vector<std::vector<int>> &graph,
         int &n, int &m, int row, int col, int count, int &ans)
{

    if (row == n && col == m)
    {
        ans = std::min(ans, count);
        return;
    }

    std::vector<int> dirRow = {-1, 0, 1, 0};
    std::vector<int> dirCol = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + dirRow[i];
        int nCol = col + dirCol[i];
        if (nRow >= 0 && nRow <= m && nCol >= 0 && nCol <= m && graph[nRow][nCol])
        {
            graph[nRow][nCol] = 0;
            dfs(graph, n, m, nRow, nCol, count + 1, ans);
            graph[nRow][nCol] = 1;
        }
    }
}

// Edge(간선)에 weight이 없는 그래프는 BFS를 사용해 최단거리를 구해줘야 한다.
void bfs(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &distance,
         int &n, int &m, int row, int col)
{
    std::vector<int> dirRow = {-1, 0, 1, 0};
    std::vector<int> dirCol = {0, -1, 0, 1};

    // 시작점 row, col
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(row, col));

    // 시작점부터 카운트해준다.
    distance[row][col]++;
    // 다시 방문하지 않도록 0으로 변경한다.
    graph[row][col] = 0;

    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dirRow[i];
            int nCol = col + dirCol[i];

            if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || !graph[nRow][nCol])
                continue;

            if (graph[nRow][nCol])
            {
                // 방문했으면 0으로 다시 방문하지 않도록 한다.
                graph[nRow][nCol] = 0;
                // 인접 좌표까지 이동한 거리
                distance[nRow][nCol] = distance[row][col] + 1;
                q.push({nRow, nCol});
            }
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

    std::vector<std::vector<int>> graph(100, std::vector<int>(100));

    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    /* std::vector<std::vector<bool>> visited(m + 1, std::vector<bool>(m + 1, false));
    int ans = INT_MAX;

    visited[1][1] = true;
    // dfs(graph, n, m, 1, 1, 1, ans);
    */
    std::vector<std::vector<int>> ans(100, std::vector<int>(100));

    bfs(graph, ans, n, m, 0, 0);

    std::cout << ans[n - 1][m - 1];
    return 0;
}