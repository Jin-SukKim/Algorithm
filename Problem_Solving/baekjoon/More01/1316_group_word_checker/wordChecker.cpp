#include <iostream>
#include <string>
#include <vector>

bool check(std::string &s)
{
    // 알파벳 배열
    std::vector<int> alphabet(26, 0);
    bool continous = false;
    int prev = s[0] - 'a';

    for (char &c : s)
    {
        int index = c - 'a';

        if (prev == index)
            continous = true;
        else
            continous = false;
        // 알파벳이 연속적으로 나오지 않고 이전에 나왔던 알파벳이
        // 다른 알파벳 이후에 다시 나오는 경우는 count - 1해준다.
        if (!continous && alphabet[index])
        {
            return false;
        }
        prev = index;
        alphabet[index]++;
    }

    return true;
}

bool check2(std::string& s)
{
    // 알파벳 배열
    std::vector<int> alphabet(26, 0);
    int prev = -1;
    for (char& c : s)
    {
        int index = c - 'a';
        // 알파벳이 사용됬었는지 확인
        if (alphabet[index] == 0)
            alphabet[index]++;
        // 알파벳이 연속적으로 쓰였는지 확인
        else if (index != prev)
            return false;
        prev = index;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    int count = 0;
    while (N--)
    {
        std::string s;
        std::cin >> s;

        count++;
        if (check(s))
            count--;
    }

    std::cout << count;

    return 0;
}
