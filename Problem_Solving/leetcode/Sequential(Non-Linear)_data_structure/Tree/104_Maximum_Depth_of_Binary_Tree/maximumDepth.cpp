/*
    104. Maximum Depth of Binary Tree
        Given the root of a binary tree, return its maximum depth.

        A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: 3
        Example 2:

        Input: root = [1,null,2]
        Output: 2

    Constraints:
        The number of nodes in the tree is in the range [0, 104].
        -100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    // 예외 처리
    if (root == nullptr)
        return 0;

    // 미리 다 선언해 실행 속도 올려주기
    int depth = 0;
    std::queue<TreeNode *> q;
    q.push(root);
    TreeNode *top;
    int size;

    while (q.size())
    {
        depth++;
        size = q.size();
        // 다음 레벨로 넘어가기 전 모든 자식 노드 순회
        for (int i = 0; i < size; i++)
        {
            top = q.front();
            q.pop();

            // 자식 노드가 있는지 확인 후 삽입
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }

    return depth;
}