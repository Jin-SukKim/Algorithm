#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    // 알파벳 26개를 -1로 설정해 단어에 포함되어 있지 않다고 초기화
    std::vector<int> alphabet(26, -1);
    for (int i = 0; i < s.length(); i++)
    {
        int a = s[i] - 'a';
        if (alphabet[a] == -1)
            alphabet[a] = i;
    }

    for (int& i : alphabet)
        std::cout << i << " ";
    return 0;
}