/*
    77. Combinations
        Given two integers n and k, return all possible combinations
        of k numbers chosen from the range [1, n].

        You may return the answer in any order.

    Example 1:
        Input: n = 4, k = 2
        Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        Explanation: There are 4 choose 2 = 6 total combinations.
        Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
        Example 2:

        Input: n = 1, k = 1
        Output: [[1]]
        Explanation: There is 1 choose 1 = 1 total combination.

    Constraints:
        1 <= n <= 20
        1 <= k <= n
*/
#include <vector>

void dfs(std::vector<std::vector<int>> &res, std::vector<int> &comb, int s, int n, int k)
{   
    // 찾은 Combination의 길이가 목표 길이(k)와 같으면 삽입
    if (comb.size() == k)
    {
        res.push_back(comb);
        return;
    }


    for (int i = s; i <= n; i++)
    {
        comb.push_back(i);
        // 현재 위치 이전의 모든 값을 제외하고 앞 요소부터 재귀함수
        dfs(res, comb, i + 1, n, k);
        // 맨 뒤 요소를 빼줘 combination에 이미 사용된 숫자를 제외
        comb.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<std::vector<int>> res;
    std::vector<int> comb;

    dfs(res, comb, 1, n, k);

    return res;
}
