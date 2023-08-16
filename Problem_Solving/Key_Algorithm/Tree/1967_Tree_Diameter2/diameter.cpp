#include <iostream>
#include <vector>

struct Node
{
    int Next;
    int Distance;
};

class Answer
{
private:
    std::vector<std::vector<Node>> tree;
    std::vector<bool> visited;
    // 트리의 diameter(지름)
    int diameter;
    int farthest;
    const int V;

public:
    Answer(std::vector<std::vector<Node>> &&tree, const int V)
        : tree(tree), V(V), diameter(0), farthest(1)
    {
        visited = std::vector<bool>(V + 1, false);
        // 소유권 박탈 (reset)
        tree.clear();
        tree.shrink_to_fit();
    };

    void dfs(int node, int dis)
    {
        if (visited[node])
            return;

        if (diameter < dis)
        {
            farthest = node;
            diameter = dis;
        }

        visited[node] = true;

        // 현재 정점에서 연결된 정점들로 이동
        for (auto &i : tree[node])
        {
            dfs(i.Next, dis + i.Distance);
        }
    }

    int getFarthest()
    {
        return farthest;
    }

    void reset()
    {
        diameter = 0;
        std::fill(visited.begin(), visited.end(), false);
    }

    void maxDis()
    {
        std::cout << diameter;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int V;
    std::cin >> V;

    std::vector<std::vector<Node>> tree(V + 1);
    for (int i = 0; i < V - 1; i++)
    {
        int from, to, dis;
        std::cin >> from >> to >> dis;
        tree[from].push_back({to, dis});
        tree[to].push_back({from, dis});
    }

    Answer a(std::move(tree), V);
    // 임의의 정점에서 가장 먼 정점을 찾아준다.
    a.dfs(1, 0);
    a.reset();
    // 찾은 가장 먼 정점에서 반대편으로 제일 먼 곳까지의 거리를 구한다.
    a.dfs(a.getFarthest(), 0);
    a.maxDis();

    return 0;
}