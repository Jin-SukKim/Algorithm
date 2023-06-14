
#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
    // 투 포인터 활용
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return {};
        std::set<int> results;
        // 정렬에 2 * O(n log n)
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        // 비교에 O(2n)
        while (i < nums1.size() && j < nums2.size())
        {
            // 값이 작은 쪽 배열의 포인터가 한 칸씩 앞으로 이동
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else
            {
                results.insert(nums1[i]);
                i++;
                j++;
            }
        }
        return std::vector<int>(results.begin(), results.end());
    }
};