#include <iostream>
#include <vector>
#include <queue>
#include <string>

void dfs(std::vector<std::vector<int>> &route,
         std::vector<bool> &circular, int &sStation, int station, int depth, bool &check)
{
    circular[station] = true;

    for (int &next : route[station])
    {
        // 순환선 체크 (최소 3개의 역이 있어야된다)
        if (next == sStation && depth >= 3)
        {
            check = true;
            return;
        }

        if (circular[next])
            continue;

        dfs(route, circular, sStation, next, depth + 1, check);

        // 순환선을 찾았다면
        if (check)
            return;
    }

    circular[station] = false;
}

void bfs(std::vector<std::vector<int>> &route,
         std::vector<bool> &circular, int &N, int &station)
{
    std::queue<int> q;
    q.push(station);

    std::vector<int> visited(N + 1, 0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 순환역에 도착했다면
        if (circular[cur])
        {
            std::cout << visited[cur] << ' ';
            return;
        }

        for (int &next : route[cur])
        {
            if (!visited[next])
            {
                // 시작역에서부터 최소거리 구하는법
                visited[next] = visited[cur] + 1;
                q.push(next);
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
    std::vector<std::vector<int>> route(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        // 양방향
        route[a].push_back(b);
        route[b].push_back(a);
    }

    std::vector<bool> circular(N + 1, 0);
    bool check = false;
    for (int i = 1; i <= N; i++)
    {
        if (check)
            break;
        // 순환선 찾기
        dfs(route, circular, i, i, 1, check);
    }

    // 최단거리 찾기
    for (int i = 1; i <= N; i++)
    {
        bfs(route, circular, N, i);
    }
    return 0;
}