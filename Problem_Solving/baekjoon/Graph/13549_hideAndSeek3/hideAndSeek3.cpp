#include <iostream>
#include <vector>
#include <queue>
void bfs(std::vector<bool> &visited, int &N, int &K)
{
    // v * 2씩 건널땐 시간이 흐르지 않으므로 이 조건을
    // 가장 먼저 진행하도록 우선순위에 따라 queue가 돌도록 해준다.
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> q;
    q.push({0, N});
    visited[N] = true;
    while (!q.empty())
    {
        int sec = q.top().first;
        int v = q.top().second;
        q.pop();

        if (v == K) {
            std::cout << sec;
            return;
        }

        // v * 2씩 건너면 시간이 흐르지 않는다.
        if (v * 2 < 100001 && !visited[v * 2])
        {
            q.push({sec, v * 2});
            visited[v * 2] = true;
        }

        if (v + 1 < 100001 && !visited[v + 1])
        {
            q.push({sec + 1, v + 1});
            visited[v + 1] = true;
        }

        if (v - 1 >= 0 && !visited[v - 1])
        {
            q.push({sec + 1, v - 1});
            visited[v - 1] = true;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<bool> visited(100001);

    bfs(visited, N, K);

    return 0;
}