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
    // dfs 가지치기로 필요한 노드 탐색(최적화)
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;

        // 이진 탐색 트리는 왼쪽이 항상 작고 오른쪽이 항상 크기에
        // 현재 노드가 low이나 high 범위 밖인 경우 탐색할 필요가 없기에 return해준다.
        
        // low보다 작으면 왼쪽은 더이상 갈 필요 없기에 오른쪽만 탐색
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        // high보다 크면 오른쪽은 갈 필요 없어 왼쪽만 탐색
        else if (high < root->val)
            return rangeSumBST(root->left, low, high);

        return root->val + rangeSumBST(root->left, low, high) 
            + rangeSumBST(root->right, low, high);
    }
};