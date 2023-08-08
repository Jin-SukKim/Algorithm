#include <iostream>
#include <vector>
#include <stack>
#include <string>

enum Color
{
    RED,
    BLUE
};

/*
    그래프의 정점의 집합을 둘로 나눴을 떄, 각 집합에 속한 정점끼리는
    서로 인접하지 않고 분할할 수 있는 그래프를 이분 그래프(bipartite graph)라 한다.
    즉, 방문한 정점을 색으로 칠할 때 서로 인접한 정점이 다른 색을 가지고 있어야 한다.
    a - c, b - c는 이분 그래프고
    a - c, b - c, c - d, d - b는 인접한 정점인 b와 d가 같은 색이기 떄문에 이분 그래프가 아니다.
*/
bool dfs(std::vector<std::vector<int>> &graph, std::vector<int> &visited,
         int v)
{
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(v, Color::RED));

    while (!stack.empty())
    {
        auto top = stack.top();
        stack.pop();

        for (int &i : graph[top.first])
        {
            if (visited[i] == -1)
            {
                visited[i] = (top.second + 1) % 2;
                stack.push({i, (top.second + 1) % 2});
            }
            if (visited[i] == top.second)
                return false;
        }
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        int N, M;
        std::cin >> N >> M;

        std::vector<std::vector<int>> graph(N + 1);

        for (int i = 0; i < M; i++)
        {
            int a, b;
            std::cin >> a >> b;
            // 양방향 간선처리 (무방향)
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        std::vector<int> visited(N + 1, -1);

        std::string check = "YES";
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == -1)
            {
                if (!dfs(graph, visited, i)) {
                    check = "NO";
                    break;
                }
            }
        }
        std::cout << check << '\n';
    }

    return 0;
}