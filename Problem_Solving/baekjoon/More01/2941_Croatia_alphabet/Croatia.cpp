#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::cin >> s;

    // 크로아티아 알파벳
    int count = 0;
    // '=', '-', 'j'인 경우 이전 알파벳을 확인해줘야 한다.
    char prev = s[0], pprev;
    for (char& c : s)
    {
        count++;
        if (c == '-')
            count--;
        else if (c == '=')
        {   
            count--;
            // "z="이면 현재 알파벳의 두 개전 알파벳을 확인해 "dz="가 맞는지 확인해준다.
            if (prev == 'z' && pprev =='d')
                count--;
        }
        else if (c == 'j')
            if (prev == 'l' || prev == 'n')
                count--;
        pprev = prev;
        prev = c;
    }

    std::cout << count;
        
    return 0;
}
