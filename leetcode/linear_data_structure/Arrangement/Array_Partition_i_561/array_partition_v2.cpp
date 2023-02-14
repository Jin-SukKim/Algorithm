#include <vector>
#include <algorithm>

// 56ms, 28.3MB
int arrayPairSum(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());

    int sum = 0;
    for(int i = 0; i < nums.size(); i += 2) {
        sum += nums.at(i);
    }

    return sum;
}