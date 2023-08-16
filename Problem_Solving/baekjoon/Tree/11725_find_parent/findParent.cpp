#include <iostream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>> &tree, std::vector<bool> &visited,
         std::vector<int> &ans)
{
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int &i : tree[f])
        {
            // 다음 노드의 부모 노드 저장
            if (!visited[i])
            {
                visited[i] = true;
                ans[i] = f;
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

    std::vector<std::vector<int>> tree(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    std::vector<bool> visited(N + 1);
    std::vector<int> ans(N + 1);

    bfs(tree, visited, ans);

    for (int i = 2; i <= N; i++)
        std::cout << ans[i] << '\n';
    return 0;
}