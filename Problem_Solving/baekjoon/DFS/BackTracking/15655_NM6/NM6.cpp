#include <iostream>
#include <vector>
#include <algorithm>

// 이전까지 도달했던 visited 배열을 사용한다.
// 즉 첫번째는 모두 false은 배열을 두번째는 첫번째 index만 true 그 다음은 두번째까지 true
void backTracking(std::vector<int> &nums, std::vector<bool> visited, std::vector<int> &ans,
                  int depth, int &n, int &m)
{
    if (depth == m)
    {
        for (int &i : ans)
            std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // 방문하지 않은 곳
        if (!visited[i])
        {
            visited[i] = true;
            ans[depth] = nums[i];
            backTracking(nums, visited, ans, depth + 1, n, m);
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
    std::vector<bool> visited(n, false);
    std::vector<int> ans(m);

    backTracking(nums, visited, ans, 0, n, m);

    return 0;
}