#include <vector>
#include <queue>

// 메모리 최적화, 시간 단축
class Solution
{
public:
    struct comp
    {
        bool operator()(std::vector<int> &a, std::vector<int> &b)
        {
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        }
    };
    /*
        유클리드 거리 공식을 사용한다. (피타고라스 공식에서 2d 좌표)
        sqrt((x2 - x1)^2 + (y2 - y1)^2)
        원점(0,0)에서 시작하므로 sqrt((x2 + y2)^2)로 표현할 수 있다.
        sqrt()는 계산이 오래걸리므로 임의로 무시한다.
    */
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        std::priority_queue<std::vector<int>,
                            std::vector<std::vector<int>>, comp>
            distance(points.begin(), points.end());

        std::vector<std::vector<int>> results;
        while (k--)
        {
            results.push_back(distance.top());
            distance.pop();
        }

        return results;
    }
};