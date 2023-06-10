/*
    310. Minimum Height Trees
        A tree is an undirected graph in which any two vertices are 
        connected by exactly one path. In other words, 
        any connected graph without simple cycles is a tree.

        Given a tree of n nodes labelled from 0 to n - 1, 
        and an array of n - 1 edges where edges[i] = [ai, bi] indicates 
        that there is an undirected edge between the two nodes ai and bi 
        in the tree, you can choose any node of the tree as the root. 
        When you select a node x as the root, the result tree has height h. 
        Among all possible rooted trees, those with minimum height 
        (i.e. min(h))  are called minimum height trees (MHTs).

        Return a list of all MHTs' root labels. 
        You can return the answer in any order.

        The height of a rooted tree is the number of edges on 
        the longest downward path between the root and a leaf.

    Example 1:
        Input: n = 4, edges = [[1,0],[1,2],[1,3]]
        Output: [1]
        Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
    
    Example 2:
        Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
        Output: [3,4]

    Constraints:
        1 <= n <= 2 * 104
        edges.length == n - 1
        0 <= ai, bi < n
        ai != bi
        All the pairs (ai, bi) are distinct.
        The given input is guaranteed to be a tree and there will be no repeated edges.
*/
/*
    노드 개수와 '무방향' 그래프를 입력받아 트리가 최소 높이가 되는 루트의
    목록을 return
*/
#include <vector>
#include <unordered_set>
#include <queue>

// need to improve
class Solution {
public:
    // 최소 높이를 구성하려면 가장 가운데 있는 값이 루트여야 한다.
    // 입력값을 토대로 그래프를 구성해 본 뒤 가장자리부터 노드를 제거해 나가면
    // 가장 마지막에 남을 루트가 될 노드를 찾을 수 있다.
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n <= 1)
            return {0};

        // undirected 그래프이므로 트리의 부모와 자식은 양쪽 노드 모두 번갈아 가능하다.
        std::vector<std::unordered_set<int>> graph(n);
        for (auto e : edges)
        {   
            // 양방향으로 그래프 구성
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        std::queue<int> leaves; // queue가 랜덤 access가 불필요할 때는 빠르다.
        // 제일 끝에 있는 노드인 리프 노드를 찾는다.
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1)
                leaves.push(i);
        }

        
        // 마지막에 남은 값이 홀수 개일 때는 루트는 최종 1개가 되지만,
        // 짝수 개일 때는 2개가 될수 있다.
        while (n > 2)
        {   
            int size = leaves.size();
            n -= size;
            while(size--)
            {
                // 리프 노드 제거
                int neighbor = *graph[leaves.front()].begin();
                graph[neighbor].erase(leaves.front());
                leaves.pop();

                if (graph[neighbor].size() == 1)
                    leaves.push(neighbor);
            }
        }

        
        std::vector<int> res;
        while (leaves.size())
        {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> edges =
    {
        {0, 1},
        {0, 2}
    };
    Solution s;
    s.findMinHeightTrees(3, edges);
    return 0;
}