#include <iostream>
#include <vector>
#include <queue>
void bfs(std::vector<bool>& visited, int& N, int& K)
{
    std::queue<std::pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty())
    {
        int f = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (f == K)
            return;

        if (visited[f - 1] || visited[f + 1] || visited[f * 2])
            continue;

        q.push({f - 1, sec + 1});
        q.push({f + 1, sec + 1});
        q.push({f * 2, sec + 1});
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    return 0;
}