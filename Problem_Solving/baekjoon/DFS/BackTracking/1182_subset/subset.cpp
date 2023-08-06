#include <iostream>
#include <vector>

void backTracking(std::vector<int> &nums,
                  int &N, int &S, int index,int& count, int sum)
{
    // 모든 수를 다 더한 경우
    if (index == N) return;
    // 지금까지의 sum에 현재를 더해준 뒤 체크
    if (sum + nums[index] == S) count++;

    // 부분집합이기에 건너뛰는 경우
    // 현재 숫자를 안더하고 넘어가 다음 숫자를 받는 경우
    backTracking(nums, N, S, index + 1, count, sum);
    
    // 현재 숫자를 더하는 경우
    backTracking(nums, N, S, index + 1, count, sum + nums[index]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, S;
    std::cin >> N >> S;

    std::vector<int> nums(N);
    for (int i = 0; i < N; i++)
        std::cin >> nums[i];

    int count;

    backTracking(nums, N, S, 0, count, 0);
    std::cout << count;
    return 0;
}