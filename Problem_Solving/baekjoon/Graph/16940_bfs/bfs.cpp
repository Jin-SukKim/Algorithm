#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         std::vector<int> &ans)
{
    std::queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        ans.push_back(n);

        for (int &i : graph[n])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 벡터에 입력된 순서
    std::vector<int> order(N + 1);
    // graph를 정렬하기 위한 기준 벡터
    std::vector<int> bfsOrder(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> order[i];
        // 각 숫자가 입력받은 순서
        bfsOrder[order[i]] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end(), [&](const int &a, const int &b)
                 { return bfsOrder[a] < bfsOrder[b]; });
    }

    std::vector<bool> visited(N + 1);
    std::vector<int> ans;
    ans.push_back(0);
   
    bfs(graph, visited, ans);
    
    if (ans == order)
       std::cout << 1;
    else
        std::cout << 0;
    return 0;
}