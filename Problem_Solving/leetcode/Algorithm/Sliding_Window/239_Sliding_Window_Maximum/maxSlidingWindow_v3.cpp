#include <vector>
#include <deque>
class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        std::vector<int> results;
        std::deque<int> q;

        for (int i = 0; i < nums.size(); i++)
        {
            if (q.size() && q.front() <= i - k)
                q.pop_front();
            
            while (q.size() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if (i >= k - 1)
                results.push_back(nums[q.front()]);
        }

        return results;
    }
};

int main()
{
    std::vector<int> nums =
        {
            1,3,1,2,0,5
            };
    Solution s;
    s.maxSlidingWindow(nums, 3);
    return 0;
}