#include <iostream>
#include <algorithm>
int main()
{
    int d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;
    int prize = 0;
    // 같은 눈이 3개가 나오는 경우
    if (d1 == d2 && d2 == d3)
        prize = 10000 + d1 * 1000;
    // 같은 눈이 2개만 나오는 경우
    else if (d1 == d2 || d1 == d3)
        prize = 1000 + d1 * 100;
    else if (d2 == d3)
        prize = 1000 + d2 * 100;
    // 모두 다른 눈이 나오는 경우
    else
        prize = std::max(std::max(d1, d2), d3) * 100;

    std::cout << prize;
    return 0;
}