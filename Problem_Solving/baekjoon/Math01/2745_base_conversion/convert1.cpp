#include <iostream>
#include <string>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    int base;

    std::cin >> s >> base;
    
    int res = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        int val = s[length - 1 - i];
        // 첫째자리수부터 진법 계산하기 위해 입력받은 string의 맨 마지막 값을 가져온다.
        if (std::isalpha(val))
            // 숫자 10 이후엔 알파벳으로 표현한다.
            val = val - 'A' + 10;
        else
            val = val - '0';
         
        // 진법은 한 자리수가 올라갈 수록 base에 i만큼 제곱을 해준다.
        res += val * std::pow(base, i);
    }
    std::cout << res;

    return 0;
}
