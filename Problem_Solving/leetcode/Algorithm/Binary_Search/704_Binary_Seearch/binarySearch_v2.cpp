#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // 비교하는 값이 더 작아 왼쪽 배열은 비교할 필요가 없다.
            if (nums[mid] < target)
                left = mid + 1;
            // 비교하는 값이 더 크므로 오른쪽 배열은 비교할 필요가 없다.
            else if (nums[mid] > target)
                right = mid - 1;
            // 목표를 찾은 것
            else
                return mid;
        }

        return -1;
    }
};