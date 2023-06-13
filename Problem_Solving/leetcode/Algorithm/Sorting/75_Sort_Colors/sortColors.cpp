/*
    75. Sort Colors
        Given an array nums with n objects colored red, white, or blue, 
        sort them in-place so that objects of the same color are adjacent, 
        with the colors in the order red, white, and blue.

        We will use the integers 0, 1, and 2 to represent the color 
        red, white, and blue, respectively.

        You must solve this problem without using the library's sort function.

    Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]

    Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]
    
    Constraints:
        n == nums.length
        1 <= n <= 300
        nums[i] is either 0, 1, or 2.

    Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <vector>
// red = 0, white = 1, blue = 2
class Solution {
public:
    void swap(int& a, int& b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    // 네덜란드 국기 문제로 매우 유명한 문제 중 하나다.
    // 퀵 정렬 개선 알고리즘을 사용한다.
    void sortColors(std::vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size();
        
        // white가 움직이며 기준(mid)로 비교가 이뤄진다.
        // red와 blue 포인터는 오른쪽과 왼쪽으로 이동하며 간격이 좁아지는 형태가 된다.
        // 정렬이 끝나면 white와 blue포인터는 겹치고 red 포인터는 1보다 작은 index의 +1 지점에 온다.  
        while (white < blue)
        {
            // white == 1을 기준으로 작으면 왼쪽인 red와 swap해준다.
            if (nums[white] < 1)
            {
                swap(nums[red], nums[white]);
                white++;
                red++;
            }
            // 1보다 큰 경우 오른쪽인 blue와 swap
            else if (nums[white] > 1)
            {
                blue--;
                swap(nums[white], nums[blue]);
            }
            // 기준이되는 1인 값은 white만 계속 이동시킨다.
            else
                white++;
        }
    }
};

int main()
{
    std::vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);

    return 0;
}