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
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

std::string removeDuplicateLetters(std::string s)
{
    // 집합으로 중복 문자 제거 및 정렬
    std::set<char> letters(s.begin(), s.end());

    for (char c : letters)
    {
        int pos = s.find(c);
        std::set<char> suffix(s.begin() + pos, s.end());
        if (letters == suffix)
        {
            //std::string::assign(suffix.begin() + 1, suffix.end());
            return c + removeDuplicateLetters(s.substr(pos));
        }
    }

    return "";
}

std::string removeDuplicateLetters2(std::string s)
{
    // cnt for storing frequency of characters
    // vis for marking visited characters
    vector<int> cnt(26, 0), vis(26, 0);

    string res = "";
    int n = s.size();

    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < n; ++i)
    {
        // decrease cnt of current character
        cnt[s[i] - 'a']--;

        // If character is not already
        // in answer
        if (!vis[s[i] - 'a'])
        {
            // Last character > s[i]
            // and its count > 0
            while (res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0)
            {
                // marking letter visited
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }

            // Add s[i] in res and
            // mark it visited
            res += s[i];
            vis[s[i] - 'a'] = 1;
        }
    }
    // return resultant string
    return res;
}

string removeDuplicateLetters(string s)
{
    unordered_map<char, int> cnts;
    string ret;
    stack<char> stk;
    vector<bool> isVisited(26, false);
    for (char each : s)
        cnts[each]++;
    for (int i = 0; i < s.size(); cnts[s[i]]--, ++i)
    {
        if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i]))
            continue;
        while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0)
        {
            isVisited[stk.top() - 'a'] = false;
            stk.pop();
        }
        stk.push(s[i]);
        isVisited[s[i] - 'a'] = true;
    }
    while (!stk.empty())
    {
        ret.push_back(stk.top());
        stk.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string removeDuplicateLetters4(string s)
{
    stack<int> stc;
    unordered_map<int, bool> visited;
    int lastIdx[26];
    string ans = "";
    for (int i = 1; i <= 26; i++)
        visited[i] = false;

    for (int i = 0; i < s.size(); i++)
        lastIdx[s[i] - 'a'] = i;

    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] - 'a';
        if (visited[val])
            continue;
        while (!stc.empty() && stc.top() > val && lastIdx[stc.top()] > i)
        {
            visited[stc.top()] = false;
            stc.pop();
        }
        stc.push(val);
        visited[val] = true;
    }
    while (!stc.empty())
    {
        ans += stc.top() + 'a';
        stc.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string removeDuplicateLetters(string s)
{
    int *count = new int[26];
    bool *taken = new bool[26];

    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
        taken[i] = 0; // false
    }

    for (auto it : s)
    {
        int ch = it - 97;
        count[ch]++;
    }
    string result = "";
    for (auto it : s)
    {
        int ch = it - 97; // 97 is the ascii value of 'a'
                          // whenever you do any operation on characters, you are mainly doing operations on their ascii value
        // if you subtract two characters, you'll get result as ascii value. And then it's upto on you if you want to convert that ascii into character or want it into "int" only.
        count[ch]--;

        if (taken[ch]) // already present in result
            continue;

        while (!result.empty() && it < result.back() && count[result.back() - 97])
        {
            taken[result.back() - 97] = false; // we don't want this bigger in front side in resultant string and due to it's reptition in upcoming stream, can be placed further according to requirement. so,now not in result
            result.pop_back();
        }
        result += it;
        taken[ch] = true; // mark that we have taken smallest ascii value character, here taking into result
    }

    return result;
}