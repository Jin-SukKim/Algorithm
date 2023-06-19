/*
    53. Maximum Subarray
        Given an integer array nums, find the subarray
        with the largest sum, and return its sum.

    Example 1:
        Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
        Output: 6
        Explanation: The subarray [4,-1,2,1] has the largest sum 6.
    
    Example 2:
        Input: nums = [1]
        Output: 1
        Explanation: The subarray [1] has the largest sum 1.
    
    Example 3:
        Input: nums = [5,4,-1,7,8]
        Output: 23
        Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
    
    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104

    Follow up: If you have figured out the O(n) solution, 
    try coding another solution using the divide and conquer approach, 
    which is more subtle.
*/
#include <vector>
class Solution {
public:
    // Memoization, 앞에서부터 계삭 값을 계산하며 누적 합을 계산하나 0 이하가 되면 초기화시킨다.
    int maxSubArray(std::vector<int>& nums) {
        int results = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int prev = nums[i - 1];
            if (prev > 0)
                nums[i] += prev;
            if (nums[i] > results)
                results = nums[i];
        }
            
        return results;
    }
};

int main()
{
    std::vector<int> nums = {
        -2,1,-3,4,-1,2,1,-5,4
    };
    Solution s;
    s.maxSubArray(nums);
    return 0;
}