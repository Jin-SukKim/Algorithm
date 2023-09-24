#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    std::set<char> skipChar(skip.begin(), skip.end());
    
    for (char& c : s)
    {
        int i = 0;
        int idx = c - 'a';
        while (i < index)
        {
            idx = (idx + 1) % 26;
            if (skipChar.count(idx + 'a'))
                continue;
            i++;
        }
        c = idx + 'a';
    }
    return s;
}