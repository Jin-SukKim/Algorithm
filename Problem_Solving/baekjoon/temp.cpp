#include <iostream>
#include <vector>
#include <queue>

// union으로 두 개의 struct이 한 struct 용량의 메모리를 공용으로 사용하도록 한다.
// 이렇게 하면 left, right로 부르거나 col, row로도 부를수 있다.
// 즉 node는 int 2개의 메모리를 가지고 있는 것이다.
union node
{
    struct
    {
        int left, right;
    };
    struct
    {
        int col, row;
    };
};

void setGraph(std::vector<node> &tree, std::vector<int> &minRow, std::vector<int> &maxRow,
              int &node, int col, int &row)
{
    if (node == -1)
        return;

    // inorder 형태로 순회
    setGraph(tree, minRow, maxRow, tree[node].left, col + 1, row);
    minRow[col] = std::min(minRow[col], row);
    maxRow[col] = std::max(minRow[col], row);
    row++;
    setGraph(tree, minRow, maxRow, tree[node].right, col + 1, row);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<node> tree(N + 1);
    // root 찾기
    // root는 최상위 노드 이므로 단 한번만 나올 것이다.
    // 숫자는 1부터 N까지이므로 나온 수를 모두 더해주면 N * (N + 1) / 2가 된다.
    // root는 부모 노드로 한 번만 나오므로 앞으로 나올 자식 노드들을 모두 빼주면
    // 결국 최상위 부모 노드로써 한번만 나온 root만 남게된다.
    int root = N * (N + 1) / 2;
    for (int i = 1; i <= N; i++)
    {
        int parent, left, right;
        std::cin >> parent >> left >> right;
        tree[parent] = {left, right};

        if (left != -1)
            root -= left;
        if (right != -1)
            root -= right;
    }

    std::vector<int> minRow;
    std::vector<int> maxRow;
    int row = 1;
    setGraph(tree, minRow, maxRow, root, 1, row);

    return 0;
}