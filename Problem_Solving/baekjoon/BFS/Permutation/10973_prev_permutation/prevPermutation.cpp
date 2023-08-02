#include <iostream>
#include <vector>
#include <algorithm>

// algorithm 라이브러리에 prev_permutation() 함수가 있다.
// 이전 순열을 찾는다 
bool prev_permutation(std::vector<int>& nums, int n)
{
    int i = n - 1;

    // 뒤에서 부터 오름차순의 첫 index를 찾는다.
    while (i > 0 && nums[i - 1] < nums[i])
        i--;
    
    // 모두 오름차순이면 첫 순열
    if (i <= 0)
        return false;

    i--;
    int j = n - 1;
    // 기준값보다 작은 값중 가장 큰 값을 찾는다.
    while (nums[i] < nums[j])
        j--;

    std::swap(nums[i++], nums[j]);

    // 기준값 index + 1부터는 내림차순으로 정렬
    std::sort(nums.begin() + i, nums.end(), std::greater<int>());

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    if (prev_permutation(nums, n))
    {
        for (int& i : nums)
            std::cout << i << ' ';
    }
    else
        std::cout << -1;
    return 0;
}