/*
    217. Contains Duplicate - Easy
    
    Given an integer array nums, return true if any value appears at least twice 
    in the array, and return false if every element is distinct.

    Example 1:

        Input: nums = [1,2,3,1]
        Output: true
        Example 2:

        Input: nums = [1,2,3,4]
        Output: false
        Example 3:

        Input: nums = [1,1,1,3,3,4,3,2,4,2]
        Output: true
    Constraints:
        1 <= nums.length <= 105
        -109 <= nums[i] <= 109
*/
#include <vector>
#include <algorithm>>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // sort for comparison

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i -1] == nums[i]) // compare current value with previous value
                return true; 
        }
        return false;
    }
};