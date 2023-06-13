/*
    973. K Closest Points to Origin
        Given an array of points where points[i] = [xi, yi] represents
        a point on the X-Y plane and an integer k,
        return the k closest points to the origin (0, 0).

        The distance between two points on the X-Y plane is
        the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

        You may return the answer in any order.
        The answer is guaranteed to be unique
        (except for the order that it is in).

    Example 1:
        Input: points = [[1,3],[-2,2]], k = 1
        Output: [[-2,2]]
        Explanation:
            The distance between (1, 3) and the origin is sqrt(10).
            The distance between (-2, 2) and the origin is sqrt(8).
            Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
            We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

    Example 2:
        Input: points = [[3,3],[5,-1],[-2,4]], k = 2
        Output: [[3,3],[-2,4]]
        Explanation: The answer [[-2,4],[3,3]] would also be accepted.

    Constraints:
        1 <= k <= points.length <= 104
        -104 < xi, yi < 104
*/
#include <vector>
#include <queue>

// 평면 x-y 2d 좌표가 있을 때 원점(0,0)에서 K번 가까운 점 목록을 순서대로 출력
class Solution
{
public:
    /*
        유클리드 거리 공식을 사용한다. (피타고라스 공식에서 2d 좌표)
        sqrt((x2 - x1)^2 + (y2 - y1)^2)
        원점(0,0)에서 시작하므로 sqrt((x2 + y2)^2)로 표현할 수 있다.
        sqrt()는 계산이 오래걸리므로 임의로 무시한다.
    */
    using priority = std::pair<int, std::vector<int>>;
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        std::priority_queue<priority, std::vector<priority>, std::greater<priority>> distance;

        for (auto p : points)
        {
            int dist = p[0] * p[0] + p[1] * p[1];
            distance.push(std::make_pair(dist, p));
        }

        std::vector<std::vector<int>> result;
        while (k--)
        {
            result.push_back(distance.top().second);
            distance.pop();
        }

        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> points = {
        {1, 3},
        {-2, 2},
        {3, 3},
        {5, -1}};
    Solution s;
    s.kClosest(points, 2);
}