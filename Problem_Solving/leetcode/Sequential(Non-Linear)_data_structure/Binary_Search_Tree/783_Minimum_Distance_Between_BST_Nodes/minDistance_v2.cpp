
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
        결국 값의 차이가 가장 작은 노드들은 
        루트의 오른쪽 노드들 중 가장 아래의 제일 왼쪽에 있는 노드와
        왼쪽 노드들의 제일 아래있고 가장 오른쪽에 있는 오른쪽 노드가 될것이다.

        이 두 노드와 루트의 차이 중 값의 차이가 제일 적은 노드를 찾아 차이 값을 return 해준다.
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