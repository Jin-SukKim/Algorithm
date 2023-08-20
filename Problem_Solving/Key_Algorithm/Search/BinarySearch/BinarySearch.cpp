#include <algorithm>
#include <iostream>
#include <queue>

int binary_search(std::vector<int>& sub, int& n)
{
    int left = 0, right = sub.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // 만약 값이 같다면 mid 인덱스 return
        if (sub[mid] == n)
            return mid;

        // n이 배열의 중간 index의 수보다 크다면 왼쪽 부분 배열은
        // 모두 작은 수이므로 배제한다.
        if (n > sub[mid])
            left = mid + 1;
        // n이 배열의 중간 index의 수보다 작다면 오른쪽 부분 배열은 배제한다.
        else
            right = mid;
    }

    return left;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    
    std::vector<int> nums(N);
    for (int i = 0; i < N; i++)
        std::cin >> nums[i];

    std::vector<int> sub;
    sub.push_back(nums[0]);
    for (int i = 1; i < N; i++)
    {   
        // 부분 배열의 맨 마지막과 비교해 더 크면 추가해준다.
        if (sub.back() < nums[i])
            sub.push_back(nums[i]);
        else
        {
            // i번째 수가 부분 수열의 몇 번째 index보다 큰지 찾는다.
            int index = binary_search(sub, nums[i]);
            sub[index] = nums[i];
        }
    }

    std::cout << sub.size();

    return 0;
}