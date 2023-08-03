#include <iostream>
#include <vector>
#include <algorithm>

void backTracking(std::vector<int>& lotto, std::vector<bool> visited, 
                std::vector<int>& ans, int& n, int depth)
{
    if (depth == 6)
    {
        std::vector<int> temp = ans;
        std::sort(temp.begin(), temp.end());
        for (int& i : temp)
            std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // 방문하지 않았다면
        if (!visited[i])
        {
            visited[i] = true;
            ans[depth] = lotto[i];
            backTracking(lotto, visited, ans, n, depth + 1);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    // 0을 입력받으면 끝내준다.
    while (std::cin >> n)
    {
        std::vector<int> lotto(n);
        for (int i = 0; i < n; i++)
            std::cin >> lotto[i];

        std::vector<bool> visited(n, false);
        std::vector<int> ans(6);

        backTracking(lotto, visited, ans, n, 0);
        std::cout << '\n';
    }

    return 0;
}