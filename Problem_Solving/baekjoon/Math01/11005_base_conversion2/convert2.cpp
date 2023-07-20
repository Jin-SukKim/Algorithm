#include <iostream>
#include <string>
#include <cmath>
// 10진법을 N진법으로 바꾸는것
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    int base;

    std::cin >> n >> base;
    
    std::string s;
    while (n)
    {
        // base로 나눈 나머지 값
        int val = n % base;
        n /= base;

        if (val > 9)
        {
            // 알파벳은 10 이후 숫자를 표현
            val = val + 'A' - 10;
        }
        else
            val = val + '0';

        s += val;
    }
    std::reverse(s.begin(), s.end());

    std::cout << s;

    return 0;
}
