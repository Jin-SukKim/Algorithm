#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &cities, std::vector<bool> &visited,
         int &n, int v, int start, int depth, int cost, int &min)
{
    // 도시를 전부 방문했으면
    if (depth == n)
    {   
        // 다시 원래 도시로 갈 수 있는지
        if (cities[v][start])
        {
            // 간다면 값을 더해준다.
            min = std::min(min, cost + cities[v][start]);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // 방문하지 않았고 현재 있는 도시에서 갈 수 있는 도시일 때
        // 그리고 다음 도시를 방문해도 아직 최소 비용보다 더 적을 때
        if (!visited[i] && cities[v][i] && cost + cities[v][i] <= min)
        {
            visited[i] = true;
            dfs(cities, visited, n, i, start, depth + 1, cost + cities[v][i], min);
            visited[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> cities(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> cities[i][j];

    std::vector<bool> visited(n, false);
    int minCost = INT_MAX;

    for (int i = 0; i < n; i++){
        visited[i] = true;
        dfs(cities, visited, n, i, i, 1, 0, minCost);
        visited[i] = false;
    }

    std::cout << minCost;
    return 0;
}