#include <iostream>
int main()
{
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