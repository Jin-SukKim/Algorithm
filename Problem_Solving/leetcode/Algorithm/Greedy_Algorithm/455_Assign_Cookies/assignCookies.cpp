/*
    455. Assign Cookies
        Assume you are an awesome parent and want to give your children
        some cookies. But, you should give each child at most one cookie.

        Each child i has a greed factor g[i],
        which is the minimum size of a cookie that
        the child will be content with; and each cookie j has a size s[j].
        If s[j] >= g[i], we can assign the cookie j to the child i,
        and the child i will be content.
        Your goal is to maximize the number of your content children
        and output the maximum number.

    Example 1:
        Input: g = [1,2,3], s = [1,1]
        Output: 1
        Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
        And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
        You need to output 1.

    Example 2:
        Input: g = [1,2], s = [1,2,3]
        Output: 2
        Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
        You have 3 cookies and their sizes are big enough to gratify all of the children,
        You need to output 2.

    Constraints:
        1 <= g.length <= 3 * 104
        0 <= s.length <= 3 * 104
        1 <= g[i], s[j] <= 231 - 1
*/

/*
    g는 아이들이 만족하는 최소 쿠키의 크기, s는 각 쿠키의 크기
    최대 몇 명의 아이들에세 쿠키를 줄 수 있는지
*/
#include <vector>
#include <algorithm>
class Solution
{
public:
    
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        // 비교하기 편하게 정렬
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int child = 0, cookie = 0;

        // 만족하지 못할 때까지 그리디 진행
        while (child < g.size() && cookie < s.size())
        {
            // 아이들이 만족하면 만족한 아이 수 + 1
            if (g[child] <= s[cookie])
                child++;
            cookie++;
        }

        return child;
    }
};