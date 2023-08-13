#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         std::vector<int> &ans, int v)
{
    if (visited[v])
        return;

    visited[v] = true;
    ans.push_back(v);
    for (int &i : graph[v])
    {
        if (!visited[i])
        {
            dfs(graph, visited, ans, i);
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

    std::vector<std::vector<int>> graph(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        // 양방향 그래프
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> dfsOrder(N + 1);
    // 인접한 노드 순서 정하기
    std::vector<int> order(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> dfsOrder[i];
        order[dfsOrder[i]] = i;
    }

    // 인접한 노드를 순서대로 정렬해주기
    for (int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end(), [&](const int& a, const int& b) {
            return order[a] < order[b];
        });
    }

    std::vector<bool> visited(N + 1, false);
    std::vector<int> ans;
    ans.push_back(0);

    dfs(graph, visited, ans, 1);
    if (ans == dfsOrder)
        std::cout << 1;
    else
        std::cout << 0;
    return 0;
}