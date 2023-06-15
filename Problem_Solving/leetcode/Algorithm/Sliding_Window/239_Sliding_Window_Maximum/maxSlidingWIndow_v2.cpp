#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {   
        if (k == 0)
            return {};

        std::vector<int> results;
        std::priority_queue<std::pair<int, int>> q;

        int i = 0;
        for (; i < k; i++)
        {
            q.push(std::make_pair(nums[i], i));
        }
        results.push_back(q.top().first);

        // i 가 슬라이딩 윈도우의 오른쪽 포인터가 되고 i - k가 왼쪽 포인터가 된다.
        for (; i < nums.size(); i++)
        {   
            q.push(std::make_pair(nums[i], i));

            // 슬라이딩 윈도우 범위를 벗어나면 빼준다.
            while (q.top().second <= i - k)
                q.pop();
            
            results.push_back(q.top().first);
        }
        
        return results;
    }
};

int main() 
{
    std::vector<int> nums =
    {
        1,3,-1,-3,5,3,6,7
    };
    Solution s;
    s.maxSlidingWindow(nums, 3);
    return 0;
}