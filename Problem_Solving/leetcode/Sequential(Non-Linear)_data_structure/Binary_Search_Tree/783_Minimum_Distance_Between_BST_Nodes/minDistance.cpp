/*
    783. Minimum Distance Between BST Nodes
        Given the root of a Binary Search Tree (BST),
        return the minimum difference between the values of
        any two different nodes in the tree.

    Example 1:
        Input: root = [4,2,6,1,3]
        Output: 1

    Example 2:
        Input: root = [1,0,48,null,null,12,49]
        Output: 1


    Constraints:
        The number of nodes in the tree is in the range [2, 100].
        0 <= Node.val <= 105

    Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/
#include <limits>
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

// 두 노드 간 가장 작은 값의 차이
class Solution
{
public:
    /*
        BST의 왼쪽 자식은 항상 루트보다 작고, 오른쪽 자식은 항상 루트보다 크다.
    */
    int prev = -1;
    int res = INT_MAX;

    int minDiffInBST(TreeNode *root)
    {
        if (root->left)
            minDiffInBST(root->left);

        if (prev >= 0)
            res = std::min(res, root->val - prev);
        prev = root->val;

        if (root->right)
            minDiffInBST(root->right);

        return res;
        
    }
};