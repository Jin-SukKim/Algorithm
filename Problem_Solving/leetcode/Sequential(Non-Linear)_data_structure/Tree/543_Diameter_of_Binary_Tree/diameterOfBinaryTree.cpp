/*
    543. Diameter of Binary Tree
        Given the root of a binary tree,
        return the length of the diameter of the tree.

        The diameter of a binary tree is the length of
        the longest path between any two nodes in a tree.
        This path may or may not pass through the root.

        The length of a path between two nodes is represented by
        the number of edges between them.

    Example 1:
        Input: root = [1,2,3,4,5]
        Output: 3
        Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
        Example 2:

        Input: root = [1,2]
        Output: 1

    Constraints:
        The number of nodes in the tree is in the range [1, 104].
        -100 <= Node.val <= 100
*/
#include <stack>
#include <vector>
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

int getDepth(TreeNode* node)
{
    if (node == nullptr)
        return 0;

    std::stack<TreeNode *> s;
    s.push(node);

    TreeNode *next;
    int length = 0;
    while (s.size())
    {
        for (int i = 0; i < s.size(); i++)
        {
            next = s.top();
            s.pop();

            if (next->right)
            {
                s.push(next->right);
            }
            if (next->left)
            {
                s.push(next->left);
            }
        }
        length++;
    }

    return length;
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = getDepth(root->left);
    int right = getDepth(root->right);

    return left + right;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return 0;
}