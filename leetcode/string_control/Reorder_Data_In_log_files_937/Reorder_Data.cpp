// 937. Reorder Data in Log Files
/*
    You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

    There are two types of logs:

    Letter-logs: All words (except the identifier) consist of lowercase English letters.
    Digit-logs: All words (except the identifier) consist of digits.
    Reorder these logs so that:

    1.  The letter-logs come before all digit-logs.
    2.  The letter-logs are sorted lexicographically by their contents. 
        If their contents are the same, then sort them lexicographically by their identifiers.
    3.  The digit-logs maintain their relative ordering.
    4.  Return the final order of the logs.

    Example 1:

    Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    Explanation:
    The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
    The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
    Example 2:

    Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

    Constraints:

    1 <= logs.length <= 100
    3 <= logs[i].length <= 100
    All the tokens of logs[i] are separated by a single space.
    logs[i] is guaranteed to have an identifier and at least one word after the identifier.
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
struct compare_str {
    bool operator()(const std::string &a, const std::string &b) const { 
        return (a.substr(a.find(' ')) == b.substr(b.find(' '))) ? a < b : a.substr(a.find(' ')) < b.substr(b.find(' ')); }
};

std::vector<std::string> reorderLogFiles(std::vector<std::string> &logs)
{
    std::vector<std::string> digits;
    std::vector<std::string> strs;
    for(std::string s : logs) {
        int first = s.find(' ')+1;
        int second = s.find(' ', first);

        std::string&& check = s.substr(first, second-first);
        if (std::all_of(check.begin(), check.end(), ::isdigit))
            digits.push_back(s);
        else
            strs.push_back(s);
    }

    std::sort(strs.begin(), strs.end(), compare_str());

    logs = strs;
    logs.insert(logs.end(), digits.begin(), digits.end());
    return logs;
}

int main() {
    std::vector<std::string> s{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    s = reorderLogFiles(s);
    for (auto a : s) {
        std::cout << a << std::endl;
    }
    return 0;
}