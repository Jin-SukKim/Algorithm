#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool>& visited,
         int &v)
{
    std::stack<int> stack;
    stack.push(v);

    while (!stack.empty())
    {
        int top = stack.top();
        stack.pop();

        if (!visited[top])
        {
            visited[top] = true;
            for (int i = graph[top].size() - 1; i >= 0; i--)
                stack.push(graph[top][i]);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N+1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        // 양방향 간선처리 (무방향)
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<bool> visited(N+1, false);

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) {
            count++;
            dfs(graph, visited, i);
        }
    }

    std::cout << count;
    return 0;
}