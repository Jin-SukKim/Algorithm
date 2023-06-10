/*
    108. Convert Sorted Array to Binary Search Tree
        Given an integer array nums where the elements are sorted
        in ascending order, convert it to a height-balanced
        binary search tree.

    Example 1:
        Input: nums = [-10,-3,0,5,9]
        Output: [0,-3,9,-10,null,5]
        Explanation: [0,-10,5,null,-3,null,9] is also accepted:

    Example 2:
        Input: nums = [1,3]
        Output: [3,1]
        Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

    Constraints:
        1 <= nums.length <= 104
        -104 <= nums[i] <= 104
        nums is sorted in a strictly increasing order.
*/
#include <vector>

// 이 문제에서의 높이 균형은 모든 노드의 두 서브 트리 간 깊이 차이가
// 1 이하인 것을 의미한다.
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
    TreeNode *constructBST(std::vector<int> &nums, int begin, int end)
    {
        if (begin >= end)
            return nullptr;

        int mid = (end + begin) / 2;

        TreeNode *node = new TreeNode(nums[mid]);
        node->left = constructBST(nums, begin, mid);
        node->right = constructBST(nums, mid + 1, end);

        return node;
    }

    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int mid = nums.size() / 2;

        // 분할 정복으로 이진 검색 결과 트리 구성
        std::vector<int> subL(nums.begin(), nums.begin() + mid);
        std::vector<int> subR(nums.begin() + mid + 1, nums.end());
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(subL);
        node->right = sortedArrayToBST(subR);

        return node;
    }

    TreeNode *sortedArrayToBST2(std::vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        return constructBST(nums, 0, nums.size());
    }
};

int main() {
    std::vector<int> nums =
    {-10, -3, 0, 5, 9};

    Solution s;
    s.sortedArrayToBST2(nums);
}
