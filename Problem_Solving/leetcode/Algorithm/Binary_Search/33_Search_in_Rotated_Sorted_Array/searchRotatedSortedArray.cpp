/*
    33. Search in Rotated Sorted Array
        There is an integer array nums sorted in ascending order
        (with distinct values).

        Prior to being passed to your function,
        nums is possibly rotated at an unknown pivot index k
        (1 <= k < nums.length) such that the resulting array is [nums[k],
        nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
        For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
        and become [4,5,6,7,0,1,2].

        Given the array nums after the possible rotation
        and an integer target, return the index of target if it is in nums,
        or -1 if it is not in nums.

        You must write an algorithm with O(log n) runtime complexity.

    Example 1:
        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4

    Example 2:
        Input: nums = [4,5,6,7,0,1,2], target = 3
        Output: -1

    Example 3:
        Input: nums = [1], target = 0
        Output: -1

    Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -104 <= target <= 104
*/
#include <vector>

// 특정 피벗을 기준으로 회전하여 정렬된 배열에서 target 값의 index를 출력
// O(log n)이므로 이진 검색 알고리즘 사용

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;

        int left = 0, right = nums.size() - 1;

        // 최솟값을 찾아 pivot 설정
        // 최솟값을 찾는 이진 검색
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        int pivot = left;

        left = 0, right = nums.size() - 1;
        // pivot을 기준으로 정렬된 배열의 이진 검색
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // pivot의 위치만큼 틀어준 값을 기준으로 값을 찾아준다.
            int mid_pivot = (mid + pivot) % nums.size();

            if (nums[mid_pivot] < target)
                left = mid + 1;
            else if (nums[mid_pivot] > target)
                right = mid - 1;
            else
                return mid_pivot;
        }

        return -1;
    }
};

int main()
{
    std::vector<int> nums = {
        4,5,6,7,0,1,2
    };

    Solution s;
    s.search(nums, 0);
    return 0;
}