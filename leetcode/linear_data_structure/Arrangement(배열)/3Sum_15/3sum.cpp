/*
    Given an integer array nums, return all the triplets
    [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
    Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.

    Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    // 문제를 쉽게 풀이하기 위해 정렬
    std::sort(nums.begin(), nums.end());
    // 두번째, 세번째 값을 찾을 두 개의 포인터
    std::vector<int>::iterator left, right;

    int sum = 0;

    // 기준이 되는 포인터
    for(auto i = nums.begin(); i != nums.end()-2; i++) {
        // 만드는 3개의 값들이 중복되면 안되므로 건너뛴다.
        if (i != nums.begin() && *i == *(i-1))
            continue;
        // 중복이 되면 안되니 기준 포인터 다음부터 찾기 시작
        left = i + 1;
        right = nums.end()-1;

        while (left < right && left != nums.end() && right != i) {
            sum = *i + *left + *right;

            // 합이 0보다 작으면 왼쪽 포인터를 움직인다.
            // 정렬이 되어서 왼쪽부터 오른쪽으로 숫자가 커진다.
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result.push_back({*i, *left, *right});
                
                while (left < right && *left == *(left + 1))
                    left++;
                while (left < right && *right == *(right - 1))
                    right--;

                left++;
                right--;
            }
        }

    }

    return result;
}

int main() {
    // [[-1,-1,2],[-1,0,1],[-1,1,0],[-1,2,-1]]
    std::vector<int> test{-1,0,1,2,-1,-4}; // -4 -1 -1 0 1 2
    std::vector<std::vector<int>> result = threeSum(test);

    for(auto i : result) {
        for (auto j : i) 
            std::cout << j << ' ';
    }
    return 0;
}