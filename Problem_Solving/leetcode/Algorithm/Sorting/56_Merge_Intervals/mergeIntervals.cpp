/*
  56. Merge Intervals
        Given an array of intervals where intervals[i] = [starti, endi],
        merge all overlapping intervals, and return an array of
        the non-overlapping intervals that cover all the intervals
        in the input.

    Example 1:
        Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output: [[1,6],[8,10],[15,18]]
        Explanation: Since intervals [1,3] and [2,6] overlap,
        merge them into [1,6].

    Example 2:
        Input: intervals = [[1,4],[4,5]]
        Output: [[1,5]]
        Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    Constraints:
        1 <= intervals.length <= 104
        intervals[i].length == 2
        0 <= starti <= endi <= 104
*/
#include <vector>
#include <algorithm>

// 겹치는 구간을 병합
class Solution
{
private:
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b)
                  {
                      return a[0] < b[0];
                  });
        std::vector<std::vector<int>> list;
        for (auto i : intervals)
        {
            // 이전 아이템의 끝이 다음 아이템의 시작값보다 작으면 겹치므로 병합해준다.
            if (!list.empty() && i[0] <= list[list.size() - 1][1])
                // 이전 아이템의 끝과 다음 아이템의 끝 중 더 큰 값을 끝 값으로 사용
                list[list.size() - 1][1] = std::max(list[list.size() - 1][1], i[1]);
            else
                list.push_back(i);
        }
        return list;
    }
};

int main()
{
    std::vector<std::vector<int>> list =
        {
            {1, 3},
            {2, 6},
            {8, 10},
            {15, 18}};

    Solution s;
    s.merge(list);
    return 0;
}