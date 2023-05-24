/*
    316. Remove Duplicate Letters

    Given a string s, remove duplicate letters
    so that every letter appears once and only once.
    You must make sure your result is
    the smallest in lexicographical order
    among all possible results.

    Example 1:
        Input: s = "bcabc"
        Output: "abc"
        Example 2:

        Input: s = "cbacdcbc"
        Output: "acdb"

    Constraints:
        - 1 <= s.length <= 104
        - s consists of lowercase English letters.

    중복된 문자를 제외하고 사전식 순서(Lexiocographical order)로 나열
*/
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>

// too slow and too much space
std::string removeDuplicateLetters(std::string s)
{
    std::string::iterator begin = s.begin();
    std::string::iterator end = s.end();
    // 집합으로 중복 문자 제거 및 정렬
    std::set<char> letters(begin, end);
    std::unordered_set<char> str(begin, end);
    for (char c : letters)
    {
        int pos = s.find(c);
        std::string suffix_s(begin+pos, end);
        std::unordered_set<char> suffix(begin + pos, end);
        if (str == suffix)
        {
            // char의 위치를 찾았으므로 중복되는 char 제거
            suffix_s.erase(std::remove(suffix_s.begin(), suffix_s.end(), c), suffix_s.end());
            return c + removeDuplicateLetters(suffix_s);
        }
    }

    return "";
}