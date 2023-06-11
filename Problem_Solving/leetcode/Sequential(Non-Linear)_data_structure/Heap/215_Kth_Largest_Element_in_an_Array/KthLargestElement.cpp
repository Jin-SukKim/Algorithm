/*
    215. Kth Largest Element in an Array
        Given an integer array nums and an integer k, 
        return the kth largest element in the array.

        Note that it is the kth largest element in the sorted order,
        not the kth distinct element.

        You must solve it in O(n) time complexity.

    Example 1:
        Input: nums = [3,2,1,5,6,4], k = 2
        Output: 5
    
    Example 2:
        Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
        Output: 4
    
    Constraints:
        1 <= k <= nums.length <= 105
        -104 <= nums[i] <= 104
*/
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // 우선순위 큐로 저장하면 최대 힙으로 저장된다.
        std::priority_queue<int> queue(nums.begin(), nums.end());

        // K번째를 return하기위해 그 전은 pop으로 빼준다.
        while (--k)
            queue.pop();

        return queue.top();
    }
};


int main() {
    std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution s;
    int temp = s.findKthLargest(nums, 4);
    return 0;
}