#include <vector>
#include <queue>

// 큐를 이용한 반복구조
std::vector<int> iterative_bfs(int v, std::vector<std::vector<int>>& graph)
{
    std::vector<int> visited = {v};
    std::queue<int> queue;
    queue.push(v);

    while (!queue.empty())
    {
        v = queue.front();
        queue.pop();
        // 인접 Edge를 추출해 다음 vertex 삽입
        for (auto w : graph[v])
        {
            // 가본적 없는 vertex라면
            if (std::find(visited.begin(), visited.end(), w) == visited.end())
            {
                visited.push_back(v);
                queue.push(v);
            }
        }
    }

    return visited;
}

// 재귀함수로는 BFS를 구현할 수 없다.

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