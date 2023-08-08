#include <iostream>
#include <vector>
#include <stack>

bool dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         int v)
{
    std::stack<int> stack;
    stack.push(v);

    int depth = 0;
    int index = 0;
    while (!stack.empty())
    {
        int top = stack.top();
        stack.pop();

        if (depth == 4)
            return true;
        
        for (int& i : graph[top])
        {
            if (!visited[i] && graph[i].size())
            {
                depth++;
                visited[top] = true;
                stack.push(i);
            }
        }
    }

    return false;   
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

    std::vector<bool> visited(N, false);

    bool check = false;
    
    for (int i = 0; i < N; i++)
    {
        if (dfs(graph, visited, i))
        {
            std::cout << true;
            return 0;
        }
    }
    std::cout << false;

    return 0;
}