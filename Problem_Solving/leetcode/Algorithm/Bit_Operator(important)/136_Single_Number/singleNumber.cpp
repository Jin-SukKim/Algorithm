// XOR 풀이
/*
    136. Single Number
        Given a non-empty array of integers nums, 
        every element appears twice except for one. Find that single one.

        You must implement a solution with a linear runtime complexity 
        and use only constant extra space.

    Example 1:
        Input: nums = [2,2,1]
        Output: 1

    Example 2:
        Input: nums = [4,1,2,1,2]
        Output: 4

    Example 3:
        Input: nums = [1]
        Output: 1
    
    Constraints:
        1 <= nums.length <= 3 * 104
        -3 * 104 <= nums[i] <= 3 * 104
        Each element in the array appears twice except for one element which appears only once.
*/
#include <vector>
/*
    단 1개의 숫자를 찾는데 적당한 연산자는 XOR이다.
    XOR은 입력값이 서로 다르면 True, 서로 동일한 경우 False가 되는 논리 게이트 연산자다.
    이것을 십진수에 적용할 수 있따.
    ex) 0 ^ 0 = 0, 4 ^ 0 = 4, 4 ^ 4 = 0
*/
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int n : nums)
            // XOR 연산자를 활용 (비트 연산자)
            result ^= n;

        return result;
    }
};