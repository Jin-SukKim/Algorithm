struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
#include <queue>

class Solution
{
public:
    // 반복 구조 DFS
    int rangeSumBST(TreeNode* root, int low, int high) {
        std::stack<TreeNode*> stack;
        int sum = 0;

        stack.push(root);

        // 스택을 활용한 DFS
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();

            if (node)
            {   
                int val = node->val;
                if (val > low)
                    stack.push(node->left);
                if (val < high)
                    stack.push(node->right);
                if (low <= val && val <= high)
                    sum += val;
            }
        }

        return sum;
    }

    // 반복 구조 BFS
    int rangeSumBST2(TreeNode* root, int low, int high) {
        std::queue<TreeNode*> q;
        int sum = 0;

        q.push(root);

        // 스택을 활용한 DFS
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node)
            {   
                int val = node->val;
                if (val > low)
                    q.push(node->left);
                if (val < high)
                    q.push(node->right);
                if (low <= val && val <= high)
                    sum += val;
            }
        }

        return sum;
    }
};