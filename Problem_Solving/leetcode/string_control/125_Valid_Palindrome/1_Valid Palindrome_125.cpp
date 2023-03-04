/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
    and removing all non-alphanumeric characters, it reads the same forward and backward. 
    Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    ex1)
        Input: s = "A man, a plan, a canal: Panama"
        Output: true
        Explanation: "amanaplanacanalpanama" is a palindrome.

    ex2)
        Input: s = "race a car"
        Output: false
        Explanation: "raceacar" is not a palindrome.

    ex3)
        Input: s = " "
        Output: true
        Explanation: s is an empty string "" after removing non-alphanumeric characters.
        Since an empty string reads the same forward and backward, it is a palindrome.

    Constraints:
        1 <= s.length <= 2 * 105
        s consists only of printable ASCII characters.
*/
#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(std::string s) {
    std::string::iterator itr = s.begin();
    std::string::reverse_iterator ritr = s.rbegin();
    if(s.length() == 1)
        return true;
    while (itr != s.end() && ritr != s.rend()) {
        while (!isalnum(*itr)) {
            ++itr;
            if (itr == s.end())
                break;
        }
        while (!isalnum(*ritr)) {
            ++ritr;
            if (ritr == s.rend())
                break;
        }
        std::cout << *itr << ' ' << *ritr << std::endl;
        if(itr == s.end() && ritr == s.rend())
            break;
        if(tolower(*itr) != tolower(*ritr))
            return false;
        ++itr;
        ++ritr;
    }
    return true;
};

int main() {
    std::cout << std::boolalpha << isPalindrome("\"Stop!\" nine myriad murmur. \"Put up rum, rum, dairymen, in pots.\"") << std::endl;
    return 0;
}