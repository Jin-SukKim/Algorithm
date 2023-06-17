/*
    424. Longest Repeating Character Replacement
        You are given a string s and an integer k.
        You can choose any character of the string and
        change it to any other uppercase English character.
        You can perform this operation at most k times.

        Return the length of the longest substring containing
        the same letter you can get after performing the above operations.

    Example 1:
        Input: s = "ABAB", k = 2
        Output: 4
        Explanation: Replace the two 'A's with two 'B's or vice versa.

    Example 2:
        Input: s = "AABABBA", k = 1
        Output: 4
        Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.
        There may exists other ways to achive this answer too.

    Constraints:
        1 <= s.length <= 105
        s consists of only uppercase English letters.
        0 <= k <= s.length
*/
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
// 대문자로 구성된 문자열 s가 주어졌을 때 k번만큼의 변경으로 만들 수 있는,
// 연속으로 반복된 문자열의 가장 긴 길이를 출력하라.

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {   
        
        // 최대 길이를 찾으므로 오른쪽 포인터를 클수록 좋고, 왼쪽 포인터를 작을수록 좋다.
        int l = 0, r = 0;
        std::unordered_map<char, int> counts;
        int maxAlpha = 0;

        // 오른쪽 포인터 이동
        for (; r < s.length(); r++)
        {
            counts[s[r]]++;
            // 가장 흔하게 등장하는 문자 탐색
            maxAlpha = std::max(maxAlpha, counts[s[r]]);
            // k 초과 시 왼쪽 포인터 이동
            if (r - l + 1 - maxAlpha > k)
            {
                counts[s[l]]--;
                l++;
            }
        }
        return r - l;
    }

    int characterReplacement2(std::string s, int k)
    {   
        
        // 최대 길이를 찾으므로 오른쪽 포인터를 클수록 좋고, 왼쪽 포인터를 작을수록 좋다.
        int l = 0, r = 0;
        std::vector<int> counts(26);
        int maxAlpha = 0;

        // 오른쪽 포인터 이동
        for (; r < s.length(); r++)
        {
            counts[s[r] - 'A']++;
            // 가장 흔하게 등장하는 문자 탐색
            maxAlpha = std::max(maxAlpha, counts[s[r] - 'A']);
            // k 초과 시 왼쪽 포인터 이동
            if (r - l + 1 - maxAlpha > k)
            {
                counts[s[l] - 'A']--;
                l++;
            }
        }
        return r - l;
    }
};

int main()
{
    std::string s = "ABAB";
    Solution sol;
    sol.characterReplacement(s, 2);
    return 0;
}