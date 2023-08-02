#include <iostream>
#include <stack>
#include <vector>

void backTracking(std::vector<int> &nums, std::vector<bool>& visited, std::vector<int> &ans, int depth, int& m, int& n)
{
    // 목표한 길이인 n까지 도달했다면
    if (depth == n)
    {
        // 정답 출력
        for (int& i : ans)
            std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < m; i++)
    {
        // 방문하지 않은 곳
        if (!visited[i])
        {
            // 방문 표시
            visited[i] = true;
            // 방문한 값을 저장
            ans[depth] = nums[i];
            // 더 깊게(다음 노드로) 향한다.
            backTracking(nums, visited, ans, depth + 1, m, n);
            // backTracking으로 방문 표시를 취소해준다.
            visited[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    std::vector<int> nums(m);
    std::vector<int> ans(n);
    std::vector<bool> visited(m, false);

    for (int i = 0; i < m; i++)
        nums[i] = i + 1;
    
    if (n == 1)
    {
        for (int& i : nums)
            std::cout << i << '\n';
        return 0;
    }

 
    backTracking(nums, visited, ans, 0, m, n);


    return 0;
}