/*
    198. House Robber
        You are a professional robber planning to rob houses along a street.
        Each house has a certain amount of money stashed,
        the only constraint stopping you from robbing each of them is
        that adjacent houses have security systems connected and
        it will automatically contact the police if two adjacent houses
        were broken into on the same night.

        Given an integer array nums representing the amount of money of
        each house, return the maximum amount of money you can rob tonight
        without alerting the police.

    Example 1:
        Input: nums = [1,2,3,1]
        Output: 4
        Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
        Total amount you can rob = 1 + 3 = 4.

    Example 2:
        Input: nums = [2,7,9,3,1]
        Output: 12
        Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
        Total amount you can rob = 2 + 9 + 1 = 12.

    Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 400
*/
#include <vector>
class Solution
{
public:
    // Tabulation
    int rob(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() <= 2)
            return *std::max_element(nums.begin(), nums.end());

        std::vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(std::max(nums[0], nums[1]));

        /*
            바로 옆집은 훔칠 수 없으므로 첫 집과 옆집 숫자 중의 최댓값은 구하고,
            한 집 건넛집까지의 최댓값과 현재 집의 숫자값과의 합을 구해서 두 수 중
            더 큰 값이 정답이 된다.
        */
        for (int i = 2; i < nums.size(); i++)
            dp.push_back(std::max(dp[i - 1], dp[i - 2] + nums[i]));

        // 마지막 값
        return *dp.rbegin();
    }

    int rob2(std::vector<int>& nums) {
        // pre는 한 집 건넛집, cur는 옆집, num[i]는 첫 집
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = std::max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};