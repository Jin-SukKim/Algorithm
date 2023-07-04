#include <iostream>
int main()
{
    // 현재 시간 h : m, 요리하는데 필요한 시간 : cook
    int h, m, cook;
    std::cin >> h >> m >> cook;
    m += cook;;

    while (m > 59) {
        h++;
        if (h > 23)
            h -= 24;
        m -= 60;
    }

    std::cout << h << ' ' << m;
    return 0;
}