/*
    Given a string s, return the longest palindromic

    substring in s.

    Example 1:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:

    Input: s = "cbbd"
    Output: "bb"

    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

// Totally fine in vscode but heap-buffer-overflow from Leetcode.
// "xaabacxcabaaxcabaax" this test case causes error
#include <string>
#include <iostream>
#include <algorithm>

// expand from center to check palindrome
template<typename Iter>
std::string isPalindrome(Iter left, Iter right, std::string& s) {
    if(*left != *right)
        return std::string{*left};

    while (left != s.rbegin().base() && right != s.end() && *left == *right ) {
        --left;
        ++right;
    }
    
    return std::string(left+1, right);
}

std::string longestPalindrome(std::string s)
{   
    // two pointer to check palindrome
    std::string::iterator left = s.begin();
    std::string::iterator right = s.begin()+1;
    std::string res = "";

    if (s.length() < 2)
        return s;

    while(right != s.end()) {
        res = std::max({res, isPalindrome(left, right, s), isPalindrome(left, right+1, s)}, 
                            [] (const auto& a, const auto& b) {return a.length() < b.length();});
        ++left;
        ++right;
    }

    return res;
}

int main() {
    std::string s = "xaabacxcabaaxcabaax";
    std::cout << "xaabacxcabaaxcabaax " << std::endl;
    std::cout << longestPalindrome(s) << std::endl;

    return 0;
}