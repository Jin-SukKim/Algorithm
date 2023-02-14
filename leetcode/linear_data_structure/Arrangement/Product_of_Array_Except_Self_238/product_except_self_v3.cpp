
#include <vector>

// 20ms, 24MB (v2보다는 느리지만 메모리 사용량이 좋아졌다.)
std::vector<int> productExceptSelf(std::vector<int> &nums)
{   
    std::vector<int> result(nums.size());

    int sum = 1;
    for (int i = 0; i < nums.size(); i++) {
        result[i] = sum;
        
        sum *= nums[i];
    }

    sum = 1;
    for (int i = nums.size()-1; i >= 0; i--) {
        result[i] = result[i] * sum;
        sum *= nums[i];
    }

    return result;

}

int main() {
    std::vector<int> nums = {1,2,3,4};
    productExceptSelf(nums);
    return 0;
}