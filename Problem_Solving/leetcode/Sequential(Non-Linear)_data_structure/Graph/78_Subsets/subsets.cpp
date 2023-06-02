/*
    78. Subsets
        Given an integer array nums of unique elements,
        return all possible
        subsets (the power set).

        The solution set must not contain duplicate subsets.
        Return the solution in any order.

    Example 1:
        Input: nums = [1,2,3]
        Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
        Example 2:

        Input: nums = [0]
        Output: [[],[0]]

    Constraints:
        1 <= nums.length <= 10
        -10 <= nums[i] <= 10
        All the numbers of nums are unique.
*/
#include <vector>
void dfs(std::vector<std::vector<int>> &res, std::vector<int> &nums, std::vector<int> &comb, int index)
{ 
    // 모든 결과를 추가
    res.push_back(comb);

    for (int i = index; i < nums.size(); i++)
    {
        comb.push_back(nums[i]);
        dfs(res, nums, comb, i + 1);
        comb.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    std::vector<int> comb;

    dfs(res, nums, comb, 0);

    return res;
}