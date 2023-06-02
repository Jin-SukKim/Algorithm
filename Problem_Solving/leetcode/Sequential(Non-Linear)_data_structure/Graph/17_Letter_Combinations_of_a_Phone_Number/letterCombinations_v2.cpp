#include <vector>
#include <string>

class Solution
{
public:
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

    void dfs(std::string& digits, std::string &comb)
    {
        // combination의 길이가 digit과 같아 끝까지 탐색되면 백트래킹
        if (comb.length() == digits.length())
        {
            res.push_back(comb);
            return;
        }

        int pad = static_cast<int>(digits[comb.length()] - '0');
        for (char c : phone[pad])
        {
            comb += c;
            dfs(digits, comb);
            comb.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};
        
        std::string combinations;
        dfs(digits, combinations);

        return res;
    }
};