#include <string>
#include <unordered_set>
#include <stack>

// fast
std::string removeDuplicateLetters(std::string s)
{
    int count[256] = {0};
    // 이미 처리된 문자 여부를 확인하기 위한 unordered_set
    std::unordered_set<char> used;
    std::stack<char> result;

    for (char c : s) 
        count[c]++;

    for (char c : s)
    {
        count[c]--;

        if (used.count(c))
            continue;

        // 현재 char이 스택에 쌓여 있는문자(이전 문자보다 앞선 문자)이고,
        // 뒤에 붙일 문자가 있다면(중복문자) 스택에서 제거
        while (result.size() && c < result.top() && count[result.top()] > 0) 
        {
            used.erase(result.top());
            result.pop();
        }

        result.push(c);
        used.emplace(c);
    }

    std::string res;
    while (!result.empty())
    {
        res += result.top();
        result.pop();
    }
    std::reverse(res.begin(), res.end());

    return res;
}

int main() 
{
    std::string s("cbacdcbc");
    removeDuplicateLetters(s);
    return 0;
}