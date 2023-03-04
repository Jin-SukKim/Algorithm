#include <vector>

// 19 ms, 25 MB (속도 증가)
std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> result;

    int size = nums.size();
    int sum = 1;
    for (int i = 0; i < size; i++)
    {
        result.push_back(sum);

        sum *= nums[i];
    }

    sum = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        result[i] = result[i] * sum;
        sum *= nums[i];
    }

    return result;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4};
    productExceptSelf(nums);
    return 0;
}