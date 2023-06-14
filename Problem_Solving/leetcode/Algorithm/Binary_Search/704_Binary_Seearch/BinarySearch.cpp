/*
    704. Binary Search
        Given an array of integers nums which is sorted in ascending order, 
        and an integer target, write a function to search target in nums. 
        If target exists, then return its index. Otherwise, return -1.

        You must write an algorithm with O(log n) runtime complexity.

    Example 1:
        Input: nums = [-1,0,3,5,9,12], target = 9
        Output: 4
        Explanation: 9 exists in nums and its index is 4

    Example 2:
        Input: nums = [-1,0,3,5,9,12], target = 2
        Output: -1
        Explanation: 2 does not exist in nums so return -1
    
    Constraints:
        1 <= nums.length <= 104
        -104 < nums[i], target < 104
        All the integers in nums are unique.
        nums is sorted in ascending order.
*/
#include <vector>

class Solution {
public:
    int binarySearch(std::vector<int>& nums, int& left, int& right, int& target)
    {
        // 절반씩 범위를 줄여나가며 재귀호출
        if (left <= right)
        {
            // 중간 값을 비교해 분할해나간다.
            int mid = (left + right) / 2;

            if (nums[mid] < target)
                return binarySearch(nums, ++mid, right, target);
            else if (nums[mid] > target)
                return binarySearch(nums, left, --mid, target);
            else
                return mid;
        }
        else
            return -1;
    }
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        return binarySearch(nums, left, right, target);
    }
};