// 344. Reverse String
/*
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:

    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
    Example 2:

    Input: s = ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]

    Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

*/
#include <iostream>
#include <vector>
// speed : 20ms, memory : 23.3MB

inline void swap(char&& a, char&& b) {
    
    typename std::remove_reference<char&&>::type t = b;
    b = a;
    a = t;
}

void reverseString(std::vector<char>& s) {
    int second = s.size() - 1;
    int first = 0;
    while(first < second) {
        swap(std::move(s.at(first)), std::move(s.at(second)));
        ++first;
        --second;
    }
}

int main() {
    std::vector<char> s{'h','e','l','l','o'}; 
    reverseString(s);
    for (auto c : s) {
        std::cout << c << std::endl;
    }
    return 0;
}