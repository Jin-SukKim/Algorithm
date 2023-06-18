/*
    169. Majority Element
        Given an array nums of size n, return the majority element.

        The majority element is the element that appears more
        than ⌊n / 2⌋ times. You may assume that the majority element
        always exists in the array.

    Example 1:
        Input: nums = [3,2,3]
        Output: 3

    Example 2:
        Input: nums = [2,2,1,1,1,2,2]
        Output: 2

    Constraints:
        n == nums.length
        1 <= n <= 5 * 104
        -109 <= nums[i] <= 109

    Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <vector>
#include <unordered_map>
#include <algorithm>

// 과반수를 차지하는(절반을 초과하는) 엘리먼트를 출력하라
class Solution
{
public:
    // 다이나믹 프로그래밍
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> counts;
        int half = nums.size() / 2;
        for (int n : nums)
            if (++counts[n] > half)
                return n;

        return 0;
    }

    int help(std::vector<int> &nums, int l, int r)
    {
        // 최소 단위로 쪼개질 때 해당하는 값을 return
        if (l >= r)
            return 0;

        if (l + 1 == r)
            return nums[l];

        int half = l + (r - l) / 2;
        // 분할 정복으로 최소 단위로 쪼개준다.
        int a = help(nums, l, half);
        int b = help(nums, half, r);

        // 백트래킹될 때 처리하는 부분인 정복(Conquer)
        // a가 분활된 리스트 nums에서 과반수를 차지한다면 과반수인 엘리먼트인 a를 return
        // 즉 과반수인 엘리먼트를 리턴
        return std::count(nums.begin(), nums.end(), a) > nums.size() / 2 ? a : b;
    }
    // 분할 정복 - 병합 정렬과 매우 유사한 방식으로 풀이
    int majorityElement2(std::vector<int> &nums)
    {
        if (nums.empty())
            return NULL;

        if (nums.size() == 1)
            return nums[0];

        return help(nums, 0, nums.size());
    }

    // 분할 정복 - 병합 정렬과 매우 유사한 방식으로 풀이
    int majorityElement3(std::vector<int> nums)
    {
        // 최소 단위로 쪼개질 때 해당하는 값을 return
        if (nums.empty())
            return 0;

        if (nums.size() == 1)
            return nums[0];

        auto half = nums.begin() + nums.size() / 2;
        // 분할 정복으로 최소 단위로 쪼개준다.
        int a = majorityElement(std::vector<int>(nums.begin(), half));
        int b = majorityElement(std::vector<int>(half , nums.end() ));

        // 백트래킹될 때 처리하는 부분인 정복(Conquer)
        // a가 분활된 리스트 nums에서 과반수를 차지한다면 과반수인 엘리먼트인 a를 return
        // 즉 과반수인 엘리먼트를 리턴
        return std::count(nums.begin(), nums.end(), a) > nums.size() / 2 ? a : b;
    }
};

int main() {
    std::vector<int> nums = { 2, 2 };
    Solution s;
    s.majorityElement2(nums);
    return 0;
}