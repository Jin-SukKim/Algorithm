#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::cin >> s;

    // 알파벳 숫자대로 배열 생성
    std::vector<int> alpha(26, 0);
    for (char& c : s)
    {
        // 알파벳 숫자 카운트
        alpha[std::toupper(c) - 'A']++;
    }

    std::vector<int> maxElements;
    auto index = std::max_element(alpha.begin(), alpha.end());
    while (index != alpha.end())
    {
        // 제일 많은 알파벳의 index값
        maxElements.push_back(index - alpha.begin());
        // 최대 빈도수의 알파벳이 더 있는지 찾아보기
        index = std::find(index+1, alpha.end(), *index);
    }
    
    if (maxElements.size() == 1)
    {
        char result = 'A' + maxElements[0];
        std::cout << result;
    }
    else
        std::cout << '?';
        
    return 0;
}
