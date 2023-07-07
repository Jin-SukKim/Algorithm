#include <iostream>
#include <string>

// two pointer를 활용해 좌우 끝에서부터 중앙으로 모이며 비교한다.
bool palindrome(std::string& s, int length)
{
    int left = 0, right = length - 1;

    for (int i = 0; i < length / 2; i++)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::cin >> s;

    std::cout << palindrome(s, s.length());

    return 0;
}
