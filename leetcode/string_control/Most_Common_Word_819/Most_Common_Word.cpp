// 819. Most Common Word
/*
    Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

    The words in paragraph are case-insensitive and the answer should be returned in lowercase.

    Example 1:

    Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
    Output: "ball"
    Explanation:
    "hit" occurs 3 times, but it is a banned word.
    "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
    Note that words in the paragraph are not case sensitive,
    that punctuation is ignored (even if adjacent to words, such as "ball,"),
    and that "hit" isn't the answer even though it occurs more because it is banned.
    Example 2:

    Input: paragraph = "a.", banned = []
    Output: "a"

    Constraints:

    1 <= paragraph.length <= 1000
    paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
    0 <= banned.length <= 100
    1 <= banned[i].length <= 10
    banned[i] consists of only lowercase English letters.
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <regex>

std::string mostCommonWord(std::string paragraph, std::vector<std::string> &banned)
{   
    std::regex reg("[!?',;.]");
    paragraph = std::regex_replace(paragraph, reg, " ");
    std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    std::map<std::string, int> common;
    int position = 0;
    int space;
    while (position < paragraph.length()) {
        space  = paragraph.find(' ', position);\
        if (space == position) {
            position = space + 1;
            continue;
        }
        if (space == std::string::npos) {
            std::string&& sub = paragraph.substr(position);
            if(!common.insert(std::make_pair(sub, 1)).second)
                common[sub] += 1;
            break;
        }
        
        std::string&& sub = paragraph.substr(position, space - position);
        if(!common.insert(std::make_pair(sub, 1)).second)
            common[sub] += 1;
        position = space + 1;
    }

    for (std::string& s : banned) {
        common[s] = 0;
    }

    auto res = std::max_element(common.begin(), common.end(), [] (const auto& a, const auto& b) {
        return a.second < b.second;
    });
    
    return res->first;
}

int main() {
    std::string s = "Bob. hIt, baLl";
    std::vector<std::string> banned{"ball"};
    std::cout << mostCommonWord(s, banned);
    return 0;
}