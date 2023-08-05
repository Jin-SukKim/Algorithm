#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool check(char& sign, int a, int b)
{
    if (sign == '<')
        if (a < b) return true;
    if (sign == '>')
       if (a > b) return true;
    
    return false;
}

void backTracking(std::vector<char>& signs, std::vector<bool> &visited,
         std::vector<std::string>& ans, int &k, int depth, std::string nums)
{
    if (depth == k+1)
    {
        ans.push_back(nums);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!visited[i] && (depth == 0 || check(signs[depth - 1], nums[depth - 1] - '0', i)))
        {
            visited[i] = true;
            backTracking(signs, visited, ans, k, depth + 1, nums + std::to_string(i));
            visited[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int k;
    std::cin >> k;

    std::vector<char> signs(k);
    for (int i = 0; i < k; i++)
        std::cin >> signs[i];

    std::vector<int> nums(10);
    std::vector<bool> visited(10, false);

    std::vector<std::string> ans;
    for (int i = 0; i < 10; i++)
        nums[i] = i;

    backTracking(signs, visited, ans, k, 0, "");

    std::cout << ans[ans.size() - 1] << '\n' << ans[0];
    return 0;
}