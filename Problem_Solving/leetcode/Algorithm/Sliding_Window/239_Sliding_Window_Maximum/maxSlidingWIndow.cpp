/*
    239. Sliding Window Maximum
        You are given an array of integers nums,
        there is a sliding window of size k which is moving from
        the very left of the array to the very right.
        You can only see the k numbers in the window.
        Each time the sliding window moves right by one position.

        Return the max sliding window.

    Example 1:
        Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
        Output: [3,3,5,5,6,7]
        Explanation:
        Window position                Max
        ---------------               -----
        [1  3  -1] -3  5  3  6  7       3
        1 [3  -1  -3] 5  3  6  7       3
        1  3 [-1  -3  5] 3  6  7       5
        1  3  -1 [-3  5  3] 6  7       5
        1  3  -1  -3 [5  3  6] 7       6
        1  3  -1  -3  5 [3  6  7]      7

    Example 2:
        Input: nums = [1], k = 1
        Output: [1]

    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        1 <= k <= nums.length
*/
#include <vector>
#include <deque>
#include <algorithm>

// 시간 초과

// 배열 nums가 주어졌을 때 k 크기의 슬라이딩 윈도우를 오른쪽 끝까지 이동하면서
// 최대 슬라이딩 윈도우를 구하라.
class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        /*
        for (int l = 0, r = k-1; r < nums.size(); l++, r++)
        {

        }
        */
        std::vector<int> results;
        int max = INT_MIN;
        std::deque<int> q;

        // 단순히 max함수를 사용해 비교하는 것보단
        // 필요할 때만 최댓값을 계산하기 위해 최적화를 진행해주는게 실행 시간을 줄일 수 있다.
        for (int i = 0; i < nums.size(); i++)
        {
            q.push_back(nums[i]);
            // 슬라이딩 윈도우
            if (i < k - 1)
                continue;

            // 최대값이 반영된 상태가 아니라면 현재 윈도우 전체의 최대값 계산
            // 최대값이 빠져 초기화되면 새로 추가된 값을 포함한 새 윈도우에서 최대값 찾기
            if (max == INT_MIN)
                max = *std::max_element(q.begin(), q.end());
            // 이미 최댓값이 존재한다면 새로 추가된 값이 기존 최댓값보다
            // 더 큰 경웨만 최댓값 교체
            else if (nums[i] > max)
                max = nums[i];

            // 최대값을 결과에 추가
            results.push_back(max);

            /*
                슬라이딩 윈도우는 오른쪽으로 이동하는데 시작하자마자 다시 신규 요소가
                추가될 것이므로 가장 오래된 값은 마지막에 제거한다.
                이때 만약 그 값이 현재 윈도우의 최댓값이라면 기존의 최댓값은 더 이상
                윈도우에 포함되지 않으므로 초기화 시킨다. 
            */
            if (max == q.front())
                max = INT_MIN;
            
            q.pop_front();
        }

        return results;
    }
};