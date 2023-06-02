/*
    46. Permutations
        Given an array nums of distinct integers,
        return all the possible permutations.
        You can return the answer in any order.

    Example 1:
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        Example 2:

        Input: nums = [0,1]
        Output: [[0,1],[1,0]]
        Example 3:

        Input: nums = [1]
        Output: [[1]]

    Constraints:
        - 1 <= nums.length <= 6
        - -10 <= nums[i] <= 10
        - All the integers of nums are unique.
*/
#include <vector>

void dfs(std::vector<std::vector<int>>& res, std::vector<int> &nums, int pos)
{
    if (pos == nums.size() - 1)
    {
        res.push_back(nums);
        return;
    }

    for (int i = pos; i < nums.size(); i++)
    {
        // 위치를 바꿔서 다양한 종합이 나오게 한다.
        std::swap(nums[pos], nums[i]);
        dfs(res, nums, pos + 1);
        // 다시 이전 위치로 돌아와 다른 조합이 나올 수 있도록 해준다.
        std::swap(nums[pos], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;

    if (nums.empty())
        return;

    dfs(res, nums, 0);
    return res;
}


int main() {
    std::vector<int> nums = {1, 2, 3};
    permute(nums);
    return 0;
}