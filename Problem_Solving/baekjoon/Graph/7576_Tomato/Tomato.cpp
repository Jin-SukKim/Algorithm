#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Edge(간선)에 weight이 없는 그래프는 BFS를 사용해 최단거리를 구해줘야 한다.
void bfs(std::vector<std::vector<int>> &graph, std::queue<std::pair<int, int>> &q,
         int &n, int &m)
{
    std::vector<int> dirRow = {-1, 0, 1, 0};
    std::vector<int> dirCol = {0, -1, 0, 1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dirRow[i];
            int nCol = col + dirCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && graph[nRow][nCol] == 0)
            {
                // 인접 좌표까지 이동한 날짜
                // 동시에 0이 아니게 되면서 다시 방문하지 않는다.
                graph[nRow][nCol] = graph[row][col] + 1;
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

    int M, N;
    std::cin >> M >> N;

    std::vector<std::vector<int>> graph(N, std::vector<int>(M));
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> graph[i][j];
            // 익은 토마토 위치 추가
            if (graph[i][j] == 1)
            {
                q.push(std::make_pair(i, j));
            }
        }
    }

    bfs(graph, q, N, M);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int &j : graph[i])
        {
            // 익지 않은 토마토가 있을 경우
            if (j == 0)
            {
                std::cout << "-1";
                return 0;
            }

            ans = ans < j ? j : ans;
        }
    }

    // 익은 토마토가 있는 부분부터 카운트 해줬기에 - 1
    std::cout << ans - 1;

    return 0;
}