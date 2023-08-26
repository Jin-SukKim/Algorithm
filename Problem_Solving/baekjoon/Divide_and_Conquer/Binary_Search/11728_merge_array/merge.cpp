#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums, std::vector<int>& left, std::vector<int>& right,
    int l, int r)
{
    int i = 0;
    int j = 0;
    int k = l;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }

    // 왼쪽 배열의 남은 나머지
    while (i < left.size())
        nums[k++] = left[i++];

    while (j < right.size())
        nums[k++] = right[j++];
}

// 직접 만든 함수들로 제출하면 시간 초과가 걸린다.
// mergeSort는 아마 std::vector로 left, right을 생성해서인 것 같고
// binary_search는 아직 잘 모르겠다.
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> left(N);
    for (int i = 0; i < N; i++)
        std::cin >> left[i];

    std::vector<int> right(M);
    for (int i = 0; i < M; i++)
        std::cin >> right[i];

    std::vector<int> nums(N + M);

    merge(nums, left, right, 0, N + M - 1);

    for (int& i : nums)
        std::cout << i << ' ';

    return 0;
}