/*
    39. Combination Sum
        Given an array of distinct integers candidates and
        a target integer target, return a list of all unique combinations
        of candidates where the chosen numbers sum to target.
        You may return the combinations in any order.

        The same number may be chosen from candidates
        an unlimited number of times.
        Two combinations are unique if the frequency
        of at least one of the chosen numbers is different.

        The test cases are generated such that the number of
        unique combinations that sum up to target is less
        than 150 combinations for the given input.

    Example 1:
        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
        2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
        7 is a candidate, and 7 = 7.
        These are the only two combinations.
        Example 2:

        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]
        Example 3:

        Input: candidates = [2], target = 1
        Output: []

    Constraints:
        1 <= candidates.length <= 30
        2 <= candidates[i] <= 40
        All elements of candidates are distinct.
        1 <= target <= 40
*/
#include <vector>

void dfs(std::vector<std::vector<int>>& res,std::vector<int> &candidates, int msum, int index, std::vector<int>& comb)
{
    // 목표를 초과한 경우
    if (msum < 0)
        return;
    // 0이면 조건을 만족하므로 삽입시켜준다.
    if (msum == 0)
    {
        res.push_back(comb);
        return;
    }

    // 현재 원소부터 하위 원소까지의 나열 재귀 호출
    for (int i = index; i < candidates.size(); i++)
    {
        comb.push_back(candidates[i]);
        dfs(res, candidates, msum-candidates[i], i, comb);
        comb.pop_back();
    }

}
std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    std::vector<std::vector<int>> res;
    std::vector<int> comb;

    dfs(res, candidates, target, 0, comb);

    return res;
}