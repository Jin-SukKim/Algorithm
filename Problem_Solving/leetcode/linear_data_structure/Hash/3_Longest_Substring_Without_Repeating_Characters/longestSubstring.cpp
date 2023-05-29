/*
    3. Longest Substring Without Repeating Characters
        Given a string s, find the length of the longest
        substring
        without repeating characters.

    Example 1:
        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3.
        Example 2:

        Input: s = "bbbbb"
        Output: 1
        Explanation: The answer is "b", with the length of 1.
        Example 3:

        Input: s = "pwwkew"
        Output: 3
        Explanation: The answer is "wke", with the length of 3.
        Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


    Constraints:
        - 0 <= s.length <= 5 * 104
        - s consists of English letters, digits, symbols and spaces.
*/
#include <string>
#include <vector>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, int> map;
    int max_length = 0, start = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // 중복되는 문자의 위치가 start보다 앞이거나 같으면 start위치 갱신
        if (map.count(s[i]) > 0 && map[s[i]] >= start)
            start = map[s[i]] + 1; // 현재 위치 + 1
        // 중복되지 않은 문자면 substring의 길이 갱신
        else 
            max_length = std::max(max_length, i - start + 1);
        // 문자의 현재 위치 삽입
        map[s[i]] = i;
    }

    return max_length;
}
