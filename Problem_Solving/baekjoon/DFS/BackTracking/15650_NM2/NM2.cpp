#include <iostream>
#include <stack>
#include <vector>

void dfs(std::vector<int> &nums, std::vector<bool> visited, std::vector<int> &ans, int depth, int &n, int &m)
{
    // 목표 도착
    if (depth == m)
    {
        for (int& i : ans)
            std::cout << i << " ";
        std::cout << "\n";
        return;
    }

    // 이전 노드로 돌아와도 visited를 false로 초기화해주지 않는다.
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            visited[i] = true;
            ans[depth] = nums[i];
            dfs(nums, visited, ans, depth + 1, n, m);
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
        nums[i] = i + 1;

    std::vector<bool> visited(n, false);
    std::vector<int> ans(m);

    dfs(nums, visited, ans, 0, n, m);
    
    return 0;
}