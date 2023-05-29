/*
    347. Top K Frequent Elements
        Given an integer array nums and an integer k, 
        return the k most frequent elements. 
        You may return the answer in any order.

    Example 1:
        Input: nums = [1,1,1,2,2,3], k = 2
        Output: [1,2]
        Example 2:

        Input: nums = [1], k = 1
        Output: [1]

    Constraints:
        - 1 <= nums.length <= 105
        - -104 <= nums[i] <= 104
        - k is in the range [1, the number of unique elements in the array].
        - It is guaranteed that the answer is unique.

    Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <vector>
#include <unordered_map>
#include <queue>

// 테이블과 우선순위 큐를 사용해 상위 k번만큼 추출
std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> map;
    // frequency
    for (int i : nums)
        map[i]++;

    std::vector<int> res;
    std::priority_queue<std::pair<int, int>> topk;
    for (auto itr : map)
        topk.push(std::make_pair(itr.second, itr.first));
    
    while (k--)
    {
        res.push_back(topk.top().second);
        topk.pop();
    }
    return res;
}