/*
    448. Find All Numbers Disappeared in an Array - Easy
    Given an array nums of n integers where nums[i] is in the range [1, n], 
    return an array of all the integers in the range [1, n] 
    that do not appear in nums.

    Example 1:
        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [5,6]
        Example 2:

        Input: nums = [1,1]
        Output: [2]
 
    Constraints:

        n == nums.length
        1 <= n <= 105
        1 <= nums[i] <= n
 
    Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

#include <vector>
#include <algorithm>>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // vector<int> ans(nums.size(), 0);

        // for (int i = 0; i < nums.size(); i++) {
        //     if (ans[i] == 0)
        //         ans[i] = i + 1;
        //     ans[nums[i] - 1] = -1; 
        // }    

        // auto it = std::remove(ans.begin(), ans.end(), -1);
        // ans.erase(it, ans.end());

        
        vector<int> ans;
        vector<int> freq(nums.size(), 0);
        for (const int& i : nums)
            freq[i - 1]++;
        
        for (int i = 0; i < nums.size(); i++)
            if (freq[i] == 0)
                ans.push_back(i + 1);

        return ans;

    }
};