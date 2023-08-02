#include <iostream>
#include <vector>

void backTracking(std::vector<int>& nums, std::vector<int>& ans,
int index, int depth, int& n, int& m)
{
    if (depth == m)
    {
        for (int& i : ans)
            std::cout << i << " ";
        std::cout << '\n';
        return;
    }

    // 중복값은 허용하나 이전 노드는 사용하지 않는다.
    for (int i = index; i < n; i++)
    {
        ans[depth] = nums[i];
        backTracking(nums, ans, i, depth + 1, n, m);
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

    std::vector<int> ans(m);

    backTracking(nums, ans, 0, 0, n, m);

    return 0;
}