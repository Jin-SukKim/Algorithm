#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int result = 0;
    int idx = 0;
    bool minus = false;
    for (int i = 0; i <= s.length(); i++) {
        // 더하기
        // 빼기, - 다음 나오는 모든 + 들을 먼저 더해준 뒤 뺴주면
        // 가장 작은 수를 얻을 수 있다. (모두 더한 뒤 빼는 것은 뒤의 수들을 전부 뺴는 것과 같다.)
        if (s[i] == '+' || s[i] == '-' || i == s.length()) {
            if (minus) {
                result -= std::stoi(s.substr(idx, i));
                idx = i + 1;
            } else {
                result += std::stoi(s.substr(idx, i));
                idx = i + 1;
            }
        }

        if (s[i] == '-' && !minus)
            minus = true;
    }

    std::cout << result;

    return 0;
}