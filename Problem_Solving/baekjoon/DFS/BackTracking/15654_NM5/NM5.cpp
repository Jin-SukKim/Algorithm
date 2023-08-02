#include <iostream>
#include <vector>
#include <algorithm>

void backTracking(std::vector<int> &nums, std::vector<bool> &visited, std::vector<int> &ans,
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
            visited[i] = false;
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