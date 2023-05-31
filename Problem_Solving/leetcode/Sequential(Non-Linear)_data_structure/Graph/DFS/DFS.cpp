
#include <vector>
#include <stack>
// 재귀방식
// parameters : vertex, graph 2d-array, int array
std::vector<int> recursive_dfs(int v, std::vector<std::vector<int>> graph, std::vector<int> visited = {})
{
    // 방문했던 vertex
    visited.push_back(v);
    for (auto w : graph[v])
    {
        // 방문하지 않았다면
        if (std::find(visited.begin(), visited.end(), w) == visited.end())
            visited = recursive_dfs(w, graph, visited);
    }

    return visited;
}

// 스택을 이용한 반복 구조
std::vector<int> iterative_dfs(int v, std::vector<std::vector<int>> graph)
{
    std::vector<int> visited;
    std::stack<int> stack;
    stack.push(v);
    while(!stack.empty())
    {
        int v = stack.top();
        if (std::find(visited.begin(), visited.end(), v) == visited.end())
        {
            visited.push_back(v);
            for (auto w : graph[v])
            {
                stack.push(w);
            }
        }
    }
    return visited;
}

int main()
{
    std::vector<std::vector<int>> graph =
    {
        {2, 3, 4},
        {5},
        {},
        {6,7},
        {},
        {3}
    };

    return 0;
}