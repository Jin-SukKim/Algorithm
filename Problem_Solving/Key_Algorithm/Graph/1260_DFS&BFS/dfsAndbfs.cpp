#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> visited,
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
            std::cout << top << ' ';
            for (int i = graph[top].size() - 1; i >= 0; i--)
                stack.push(graph[top][i]);
        }
    }
}

void bfs(std::vector<std::vector<int>> &graph, std::vector<bool> visited,
         int &v)
{
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        std::cout << v << ' ';

        for (int& i : graph[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
/*
    input   
    4 5 1
    1 2
    1 3
    1 4
    2 4
    3 4

    output
    1 2 4 3
    1 2 3 4 

    input
    5 5 3
    5 4
    5 2
    1 2
    3 4
    3 1

    output
    3 1 2 5 4
    3 1 4 2 5
*/
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M, V;
    std::cin >> N >> M >> V;

    std::vector<std::vector<int>> graph(N+1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        // 양방향 간선처리 (무방향)
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i <= N; i++)
        std::sort(graph[i].begin(), graph[i].end());

    std::vector<bool> visited(N+1, false);

    dfs(graph, visited, V);
    std::cout << '\n';
    bfs(graph, visited, V);
    return 0;
}