/*
    238. Product of Array Except Self
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

    Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    Follow up: Can you solve the problem in O(1) extra space complexity?
    (The output array does not count as extra space for space complexity analysis.)
*/
#include <vector>

// 자신을 중심으로 왼쪽에 있는 값들의 곱과 오른쪽 값들의 곲을 따로 구한뒤
// 둘을 곱해주면 답을 얻을 수 있다.

// 30ms, 28MB (시간과 공간 모두 개선 필요)
std::vector<int> productExceptSelf(std::vector<int> &nums)
{   
    std::vector<int> left;
    std::vector<int> right;

    auto l = nums.begin();
    auto r = nums.rbegin();

    int size = nums.size();
    int forwards = 1, backwards = 1;
    for (int i = 0; i < size; i++) {
        left.push_back(forwards);
        right.push_back(backwards);
        
        forwards *= *l;
        backwards *= *r;

        l++;
        r++;
    }

    std::vector<int> result;
    for (int i = 0; i < size; i++) {
        result.push_back(left[i] * right[size-i-1]);
    }

    return result;

}

int main() {
    std::vector<int> nums = {1,2,3,4};
    productExceptSelf(nums);
    return 0;
}