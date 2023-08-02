#include <iostream>
#include <vector>
#include <algorithm>

// algorithm 라이브러리에 next_permutation 함수가 있다.
// 다음 순열을 찾는다 (이 함수를 false가 나올 때까지 반복하면
// 순열의 처음부터 끝까지 구할 수 있다.)
bool next_permutation(std::vector<int> &nums, int n)
{
    // 마지막 index
    int i = n - 1;
    // 어디까지 내림차순인지 확인
    while (i > 0 && nums[i - 1] >= nums[i])
        i--;

    // 전부 내림차순이면 순열의 맨 마지막을 의미한다.
    if (i <= 0)
        return false;

    // 기준이 될 마지막 내림차순 앞의 index (ex: 1254면 2가 기준)
    i -= 1;
    // i의 뒤에 있는 수 기준값보다 크면서 뒤의 수 중 가장 작은 숫자를 찾는다.
    int j = n - 1;
    // 오른쪽은 내림차순으로 정렬되어 있어 index i값보다 작은 값들을 넘어가면
    // 가장 작은 수를 찾을 수 있다.
    while (nums[i] >= nums[j])
        j--;

    std::swap(nums[i++], nums[j]);

    // 기준값의 index + 1부터 끝까지 다시 오름차순으로 정렬해준다.
    std::sort(nums.begin() + i, nums.end());

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
        nums[i] = i + 1;
    
    
    do {
        for (int &i : nums)
            std::cout << i << ' ';
        std::cout << '\n';
    } while (next_permutation(nums, n));

    return 0;
}