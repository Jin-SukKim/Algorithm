#include <iostream>
#include <vector>
#include <stack>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> visited,
         int idx, int depth, bool &ans)
{
    if (depth == 4)
    {
        ans = true;
        return;
    }

    
    visited[idx] = true;
    for (int &i : graph[idx])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(graph, visited, i, depth + 1, ans);
            visited[i] = false;
        }
        if (ans)
            return;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N);
    for (int i = 0; i < M; i++)
    {
        int j, k;
        std::cin >> j >> k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }

    bool check = false;

    std::vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        dfs(graph, visited, i, 0, check);
        if (check)
            break;
    }
    std::cout << check;

    return 0;
}