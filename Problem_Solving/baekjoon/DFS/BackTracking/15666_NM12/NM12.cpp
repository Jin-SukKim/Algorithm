#include <iostream>
#include <vector>
#include <algorithm>

void backTracking(std::vector<int> &nums, std::vector<int> &ans,
                  int index, int depth, int &n, int &m)
{
    if (depth == m)
    {
        for (int &i : ans)
            std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    int last = 0;
    for (int i = index; i < n; i++)
    {
        // 연속으로 같은 수가 나오면 안된다.
        if (last != nums[i])
        {
            ans[depth] = nums[i];
            last = nums[i];
            backTracking(nums, ans, i, depth + 1, n, m);

        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    // 정렬
    std::sort(nums.begin(), nums.end());

    std::vector<int> ans(m);

    backTracking(nums, ans, 0, 0, n, m);

    return 0;
}