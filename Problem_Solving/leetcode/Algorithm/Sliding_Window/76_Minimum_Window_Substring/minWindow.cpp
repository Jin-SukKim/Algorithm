/*
    76. Minimum Window Substring
        Given two strings s and t of lengths m and n respectively, 
        return the minimum window 
        substring
        of s such that every character in t (including duplicates) is 
        included in the window. 
        If there is no such substring, return the empty string "".

        The testcases will be generated such that the answer is unique.

    Example 1:
        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
        Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    
    Example 2:
        Input: s = "a", t = "a"
        Output: "a"
        Explanation: The entire string s is the minimum window.
    
    Example 3:
        Input: s = "a", t = "aa"
        Output: ""
        Explanation: Both 'a's from t must be included in the window.
        Since the largest window of s only has one 'a', return empty string.
    
    Constraints:
        m == s.length
        n == t.length
        1 <= m, n <= 105
        s and t consist of uppercase and lowercase English letters.
    
    Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

/*
    윈도우 사이즈를 늘려가면서 찾는 것은 시간 복잡도 O(n) 제한에서 벗어난
    O(n^2)이므로 brute-force로 풀이해서는 안된다.

    이런 유형의 문제는 투 포인터를 사용하면 O(n^2)에서 O(n)으로 줄일 수 있다.
*/
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty())
            return "";

        if (s == t)
            return s;

        std::unordered_map<char, int> alpha;
        
        for (char c : t)
        {
            alpha[c]++;
        }

        int length = t.size();

        int l = 0, start = 0, end = -1;
        // 오른쪽 포인터를 이동해 윈도우 슬라이스 크기를 늘린다.
        for (int r = 0; r < s.size(); r++)
        {
            if (alpha[s[r]] > 0)
                length--;
            alpha[s[r]]--;
        
            // 필요한 문자를 다 찾으면 왼쪽 포인터를 움직여서
            // 슬라이스를 줄일 수 있는지 살핀다.
            // string에서 다음 조합을 찾기위해 alpha[s[left]]++; 를해준다.
            if (length == 0)
            {
                // 불필요한 문자를 가리키고 있다면 포인터 이동해 윈도우 크기를 줄인다
                while (l < r && alpha[s[l]] < 0)
                {
                    alpha[s[l]]++;
                    l++;
                }

                if (end == -1 || r - l <= end - start)
                {
                    start = l;
                    end = r;
                }
                alpha[s[l]]++;
                length++;
                l++;
            }
        }

        return end == -1 ? "" : s.substr(start, end - start + 1);
    }
};

int main() 
{
    std::string s = "ab";
    std::string t = "a";
    Solution sol;
    sol.minWindow(s, t);
    return 0;
}