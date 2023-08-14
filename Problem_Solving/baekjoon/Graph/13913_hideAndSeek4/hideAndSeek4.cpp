#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    bool visited[100001];
    visited[N] = N;
    // 정답까지 가는 경로
    int path[100001];

    std::queue<std::pair<int, int>> q;
    q.push({N, 0});

    std::stack<int> move;
    int seconds = 0;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        int index = f.first;
        int sec = f.second;

        // 목적지에 도달했다면
        if (index == K)
        {
            seconds = sec;
            for (int i = K; i != N; i = path[i])
            {
                move.push(i);
            }
            move.push(N);
            break;
        }

        if (index - 1 >= 0 && !visited[index - 1])
        {
            visited[index - 1] = true;
            // 다음 노드 방문전 방문했던 노드 index 저장
            path[index - 1] = index;
            q.push({index - 1, sec + 1});
        }
        if (index + 1 <= 100000 && !visited[index + 1])
        {
            visited[index + 1] = true;
            path[index + 1] = index;
            q.push({index + 1, sec + 1});
        }
        if (index * 2 <= 100000 && !visited[index * 2])
        {
            visited[index * 2] = true;
            path[index * 2] = index;
            q.push({index * 2, sec + 1});
        }
    }

    std::cout << seconds << '\n';
    while (!move.empty())
    {
        std::cout << move.top() << ' ';
        move.pop();
    }

    return 0;
}