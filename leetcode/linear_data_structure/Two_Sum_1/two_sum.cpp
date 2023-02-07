/*
    Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution,
    and you may not use the same element twice.

    You can return the answer in any order.

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]

    Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

    Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int i = 0;
    std::multimap<int, int> res;
    std::transform(nums.begin(), nums.end(), std::inserter(res, res.end()),
                    [&i] (const int& key) { return std::make_pair(key, i++);});


    // using structure bind and for each to get key and value pair from map
    for (const auto& [key, value]: res) {
        if (res.at(target-key) && value != res[target-key])
            return std::vector<int>{value, res[target-key]};
    }

    return std::vector<int>{0,0};
}

int main() {
    std::vector<int> nums{2,7,11,15};
    int target = 9;

    for(const auto& i : twoSum(nums, target))
        std::cout << i << " ";
    return 0;
}