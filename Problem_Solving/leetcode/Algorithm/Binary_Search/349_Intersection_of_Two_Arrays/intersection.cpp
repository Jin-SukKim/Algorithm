/*
    349. Intersection of Two Arrays
        Given two integer arrays nums1 and nums2, 
        return an array of their intersection. 
        Each element in the result must be unique and you may return 
        the result in any order.

    Example 1:
        Input: nums1 = [1,2,2,1], nums2 = [2,2]
        Output: [2]

    Example 2:
        Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        Output: [9,4]
        Explanation: [4,9] is also accepted.
    
    Constraints:
        1 <= nums1.length, nums2.length <= 1000
        0 <= nums1[i], nums2[i] <= 1000
*/
#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
    int search(std::vector<int>& nums, int& target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }

    // brute-force는 O(n^2)가 걸리나 이진 검색을 활용하면 O(n log n)으로 줄일 수 있다.
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return {};

        // set으로 결과 값을 얻으며 중복값을 제외
        std::set<int> results;
        // 이진 검색을 위해 정렬
        std::sort(nums2.begin(),  nums2.end());

        // 반복 O(n)
        for (int n1 : nums1)
        {
            // 이진 검색으로 일치 여부 판별 O(log n)
            int idx = search(nums2, n1);
            if (idx > -1 && nums2.size() > idx && n1 == nums2[idx])
                results.insert(n1);
        }

        return std::vector<int>(results.begin(), results.end());
    }
};

int main()
{
    std::vector<int> nums1 = {
        4,9,5
    };
    std::vector<int> nums2 = {
        9,4,9,8,4
    };
    Solution s;
    s.intersection(nums1, nums2);
    return 0;
}