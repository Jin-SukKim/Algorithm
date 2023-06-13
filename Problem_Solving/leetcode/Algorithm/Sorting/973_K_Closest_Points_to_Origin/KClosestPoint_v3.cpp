#include <vector>
#include <queue>
#include <algorithm>
// 메모리 최적화, 시간 단축 version 2보다 더 단축
// quick sort같은 정렬 알고리즘으로 시간을 더 단축할 수도 있을 것 같다.
class Solution
{
public:
    /*
        유클리드 거리 공식을 사용한다. (피타고라스 공식에서 2d 좌표)
        sqrt((x2 - x1)^2 + (y2 - y1)^2)
        원점(0,0)에서 시작하므로 sqrt((x2 + y2)^2)로 표현할 수 있다.
        sqrt()는 계산이 오래걸리므로 임의로 무시한다.
    */

    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        std::sort(points.begin(), points.end(),
                  [](std::vector<int> &a, std::vector<int> &b)
                  {
                      return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
                  });

        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
};