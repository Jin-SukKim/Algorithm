/*
    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it can trap after raining.

    Example 1:

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
    In this case, 6 units of rain water (blue section) are being trapped.

    Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9

    Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/
#include <vector>
#include <algorithm>

int trap(std::vector<int> &height)
{
    int volume = 0; // 물의 양
    auto i = height.begin();
    auto r = height.end() - 1;

    int leftMax = 0, rightMax = 0;

    while(i != r) {
        // 현재의 최고 벽 높이
        leftMax = std::max(leftMax, *i);
        rightMax = std::max(rightMax, *r);

        // 왼쪽 포인터가 오른쪽 포인터보다 작다면 왼쪽을 옮기고
        // 아니라면 오른쪽을 옮겨 최종적으로 제일 높은 벽에 도달하면 끝난다.
        if (leftMax < rightMax) {
            volume += (leftMax - *i);
            i++;
        }
        else {
            volume += (rightMax - *r);
            r--;
        }
    }

    return volume;
}