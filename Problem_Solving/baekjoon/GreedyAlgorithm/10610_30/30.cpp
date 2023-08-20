#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end(), std::greater<char>());

    // 만약 정렬했을 때 맨 뒤의 숫자가 0이라면 30의 배수가 아니다.
    if (s.back() != '0')
    {
        std::cout << -1;
        return 0;
    }

    // 30의 배수는 결국 3의 배수와 비슷한데 3의 배수는
    // 각 자리수들을 더한 값이 3으로 나누어떨어져야한다.
    // 즉, 각 자리 수의 합이 3의 배수인 수이다.
    int sum = 0;
    for (int i = 0; i < s.length(); i++) 
        sum += s[i] - '0';

    if (sum % 3 == 0)
        std::cout << s;
    else 
        std::cout << -1;
    

    return 0;
}