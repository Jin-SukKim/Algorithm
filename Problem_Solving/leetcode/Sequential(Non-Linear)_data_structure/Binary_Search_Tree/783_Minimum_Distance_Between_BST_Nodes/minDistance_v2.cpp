
#include <limits>
#include <algorithm>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 두 노드 간 가장 작은 값의 차이
class Solution
{
public:
    /*
        BST의 왼쪽 자식은 항상 루트보다 작고, 오른쪽 자식은 항상 루트보다 크다.
    */
    int minDiffInBST(TreeNode *root)
    {
        int prev = -1000000;
        int res = INT_MAX;

        std::stack<TreeNode*> stack;
        TreeNode* node = root;

        while (!stack.empty() || node)
        {
            while (node)
            {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();

            res = std::min(res, node->val - prev);
            prev = node->val;

            node = node->right;
        }

        return res;
    }
};