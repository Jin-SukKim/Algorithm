/*
    226. Invert Binary Tree
        Given the root of a binary tree, invert the tree,
        and return its root.



    Example 1:
        Input: root = [4,2,7,1,3,6,9]
        Output: [4,7,2,9,6,3,1]

    Example 2:
        Input: root = [2,1,3]
        Output: [2,3,1]

    Example 3:
        Input: root = []
        Output: []

    Constraints:
        The number of nodes in the tree is in the range [0, 100].
        -100 <= Node.val <= 100
*/
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

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::stack<TreeNode*> stack;
        stack.push(root);

        while (stack.size())
        {
            TreeNode* node = stack.top();
            stack.pop();

            if (node)
            {
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                
                stack.push(node->left);
                stack.push(node->right);
            }
        }

        return root;
    }
};