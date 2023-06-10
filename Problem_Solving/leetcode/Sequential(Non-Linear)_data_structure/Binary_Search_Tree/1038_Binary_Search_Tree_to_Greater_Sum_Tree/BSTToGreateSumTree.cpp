/*
    1038. Binary Search Tree to Greater Sum Tree
        Given the root of a Binary Search Tree (BST),
        convert it to a Greater Tree such that every key of
        the original BST is changed to the original key plus
        the sum of all keys greater than the original key in BST.

        As a reminder, a binary search tree is a tree that satisfies
        these constraints:

        The left subtree of a node contains only nodes with
        keys less than the node's key.
        The right subtree of a node contains only nodes with
        keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.

    Example 1:
        Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
        Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

    Example 2:
        Input: root = [0,null,1]
        Output: [1,null,1]

    Constraints:
        The number of nodes in the tree is in the range [1, 100].
        0 <= Node.val <= 100
        All the values in the tree are unique.
*/

// BST의 각 노드를 현재값보다 더 큰 값을 가진 모든 노드의 합으로 만든다.
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
    int sum = 0;
    // 자신보다 같거나 큰 값을 구하려면 자신을 포함한 우측 자식 노드의 합을 구하면 된다.
    // BST의 우측 자식 녿는 항상 부모보다 큰값이어서 이다.
    // 즉, 오른쪽->부모->왼쪽 순으로 움직여야 된다.
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root) {
            // 맨 우측이 가장 큰 값이기에 우측으로 이동
            bstToGst(root->right);
            // 여태까지 노드의 합
            sum += root->val;
            // 여태 값의 합을 현재 노드 값으로 바꿔준다.
            root->val = sum;
            bstToGst(root->left);
        }
        
        return root;
    }
};