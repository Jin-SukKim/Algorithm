/*
    105. Construct Binary Tree from Preorder and Inorder Traversal
        Given two integer arrays preorder and inorder where preorder is
        the preorder traversal of a binary tree and inorder is
        the inorder traversal of the same tree,
        construct and return the binary tree.

    Example 1:
        Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        Output: [3,9,20,null,null,15,7]

    Example 2:
        Input: preorder = [-1], inorder = [-1]
        Output: [-1]

    Constraints:
        1 <= preorder.length <= 3000
        inorder.length == preorder.length
        -3000 <= preorder[i], inorder[i] <= 3000
        preorder and inorder consist of unique values.
        Each value of inorder also appears in preorder.
        preorder is guaranteed to be the preorder traversal of the tree.
        inorder is guaranteed to be the inorder traversal of the tree.
*/
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
/*
전위 순회(preorder)는 현재 노드 -> 왼쪽 서브트리 -> 오른쪽 서브트리

중위(inorder)는 왼쪽 서브트리 -> 현재 노드 -> 오른쪽 서브트리

순회 종류중 2가지가 있으면 이진 트리를 복원할 수 있다.
*/
class Solution
{
public:
    // 전위 순회 결과로 중위 순회 분할 정복
    /*
        전위 결과의 첫번째 값은 root로 중위 결과를 왼쪽과 오른쪽으로 분할시킬 수 있다.
        전위 결과의 그 다음 값은 중위 결과의 왼쪽 결과의 절반을 또 분할할 수 있다.
        이런식으로 계속 분할이 가능하다.

        만약 이 값이 제일 우측에 있었다면 오른쪽 서브 트리는 없었다는 의미다.
    */
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        int index = 0;
        return convertToTree(preorder, inorder, index, 0, inorder.size() - 1);
    }

    // unordered_map을 사용하면 더 빠를수도 있다.
    TreeNode *convertToTree(std::vector<int> &preorder, std::vector<int> &inorder, int &index, int begin, int end)
    {
        if (begin >= end)
            return nullptr;

        // 중위 순회에서의 위치
        int pos = static_cast<int>(std::find(inorder.begin(), inorder.end(), preorder[index]) - inorder.begin());
        TreeNode *node = new TreeNode(preorder[index]);
        index++;
        node->left = convertToTree(preorder, inorder, index, begin, pos - 1);
        node->right = convertToTree(preorder, inorder, index, pos + 1, end);

        return node;
    }
};

int main()
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};

    Solution s;
    s.buildTree(preorder, inorder);
    return 0;
}