/*
    110. Balanced Binary Tree
        Given a binary tree, determine if it is 
        height-balanced

        A height-balanced binary tree is a binary tree in which 
        the depth of the two subtrees of every node never differs by 
        more than one.

    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: true

    Example 2:
        Input: root = [1,2,2,3,3,null,null,4,4]
        Output: false

    Example 3:
        Input: root = []
        Output: true

    Constraints:
        The number of nodes in the tree is in the range [0, 5000].
        -104 <= Node.val <= 104
*/
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

class Solution {
public:
    int check(TreeNode* node) {
        if (!node)
            return 0;

        int left = check(node->left);
        int right = check(node->right);

        // 높이 차이가 1 이상 나는 경우 -1, 아닌 경우 1 증가
        // 한번이라도 -1을 return하면 계속 return 하므로 false
        if (left == -1 || right == -1 || std::abs(left - right) > 1)
            return -1;

        // 맨 밑까지 내려가면 일단 left = right = 0이 된다.
        // 차이가 1보다 크지 않아 1씩 증가한다.
        return std::max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};