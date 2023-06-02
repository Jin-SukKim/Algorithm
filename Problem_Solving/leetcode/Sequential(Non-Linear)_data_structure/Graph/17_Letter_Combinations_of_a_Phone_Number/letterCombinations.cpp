/*
    17. Letter Combinations of a Phone Number
        Given a string containing digits from 2-9 inclusive,
        return all possible letter combinations that
        the number could represent.
        Return the answer in any order.

        A mapping of digits to letters
        (just like on the telephone buttons) is given below.
        Note that 1 does not map to any letters.

    Example 1:
        Input: digits = "23"
        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
        Example 2:

        Input: digits = ""
        Output: []
        Example 3:

        Input: digits = "2"
        Output: ["a","b","c"]

    Constraints:
        - 0 <= digits.length <= 4
        - digits[i] is a digit in the range ['2', '9'].
*/
#include <vector>
#include <string>

void dfs(std::string& digits, std::vector<std::string>& phone, 
std::vector<std::string>& result, int index, std::string& comb)
{   
    // combination의 길이가 digit과 같아 끝까지 탐색되면 백트래킹
    if (comb.length() == digits.length())
    {
        result.push_back(comb);
        return;
    }

    int pad = static_cast<int>(digits[index] - '0');
    for (int i = 0; i < phone[pad].size(); i++)
    {
        comb += phone[pad][i];
        dfs(digits, phone, result, index + 1, comb);
        comb.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    if (digits.empty())
        return {};

    std::vector<std::string> phone =
    {
        {},
        {},
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"},
    };
    
    std::vector<std::string> res;
    std::string combinations;
    dfs(digits, phone, res, 0, combinations);

    return res;
}

int main()
{
    letterCombinations("23");

    return 0;
}