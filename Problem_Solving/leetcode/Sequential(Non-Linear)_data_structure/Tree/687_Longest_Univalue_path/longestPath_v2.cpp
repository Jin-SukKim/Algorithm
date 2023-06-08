
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int length;
    int dfs(TreeNode *node, int parent)
    {
        if (node == nullptr)
            return 0;

        int left = dfs(node->left, node->val);
        int right = dfs(node->right, node->val);
        // 왼쪽과 오른쪽 자식 노드 간 거리의 합 최댓값
        length = std::max(length, left + right);

        // 노드 값이 부모의 값과 같으면 길이 + 1
        if (parent == node->val)
            return std::max(left, right) + 1;
        return 0;
    }

    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root, 0);
        return length;
    }
};