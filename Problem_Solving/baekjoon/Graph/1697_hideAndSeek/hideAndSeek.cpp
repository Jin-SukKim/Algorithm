#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    std::queue<std::pair<int, int>> q;
    int visited[100001] = {
        0,
    };

    q.push({N, 0});
    while (!q.empty())
    {
        int f = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (f < 0 || f > 100000)
            continue;

        if (f == K)
        {
            std::cout << sec;
            break;
        }

        if (f - 1 >= 0 && visited[f - 1] == 0)
        {
            visited[f - 1] = true;
            q.push({f - 1, sec + 1});
        }
        if (f + 1 <= 100000 && visited[f + 1] == 0)
        {
            visited[f + 1] = true;
            q.push({f + 1, sec + 1});
        }
        if (2 * f <= 100000 && visited[2 * f] == 0)
        {
            visited[2 * f] = true;
            q.push({2 * f, sec + 1});
        }
    }

    return 0;
}