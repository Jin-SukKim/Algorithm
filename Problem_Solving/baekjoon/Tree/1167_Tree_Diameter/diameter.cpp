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
    std::vector<std::vector<Node>> m_Tree;
    std::vector<bool> m_Visited;
    // 트리의 diameter(지름)
    int m_Diameter;
    int m_Farthest;
    const int m_V;

public:
    Answer(std::vector<std::vector<Node>> &&tree, const int V)
        : m_Tree(tree), m_V(V), m_Diameter(0), m_Farthest(1)
    {
        m_Visited = std::vector<bool>(V + 1, false);
        // 소유권 박탈 (reset)
        tree.clear();
        tree.shrink_to_fit();
    };

    void dfs(int node, int dis)
    {
        if (m_Visited[node])
            return;

        if (m_Diameter < dis)
        {
            m_Farthest = node;
            m_Diameter = dis;
        }

        m_Visited[node] = true;

        // 현재 정점에서 연결된 정점들로 이동
        for (auto &i : m_Tree[node])
        {
            dfs(i.Next, dis + i.Distance);
        }
    }

    int getFarthest()
    {
        return m_Farthest;
    }

    void reset()
    {
        m_Diameter = 0;
        std::fill(m_Visited.begin(), m_Visited.end(), false);
    }

    void maxDis()
    {
        std::cout << m_Diameter;
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
    for (int i = 0; i < V; i++)
    {
        int from;
        std::cin >> from;
        while (1)
        {
            int to, dis;
            std::cin >> to;
            if (to == -1)
                break;
            std::cin >> dis;
            tree[from].push_back({to, dis});
            tree[to].push_back({from, dis});
        }
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