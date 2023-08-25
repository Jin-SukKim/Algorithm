#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string S, T;

    std::cin >> S >> T;

    // S를 T와 같이 바꾸기 보단 T에서 A와 B를 추가하는 룰을 반대로 적용하며
    // T를 S와 같이 바꾼다.
    while (1)
    {
        if (S.size() == T.size())
        {
            if (S == T)
                std::cout << 1;
            else
                std::cout << 0;
            return 0;
        }

        if (T.back() == 'A') {
            T.pop_back();
        }
        else if (T.back() == 'B')
        {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }

    return 0;
}