#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<std::string> v;
    size_t longest = 0;
    for (int i = 0; i < 5; i++)
    {
        std::string s;
        std::cin >> s;
        v.push_back(s);
        longest = std::max(longest, s.length());
    }

    // 최대 15글자
    for (int i = 0; i < longest; i++)
    {
        // 5개의 단어
        for (int j = 0; j < 5; j++)
        {
            // 단어의 길이 범위 내에서 출력
            if (i < v[j].length())
                std::cout << v[j][i];
        }
    }

    return 0;
}
