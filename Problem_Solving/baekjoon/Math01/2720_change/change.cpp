#include <iostream>
#include <string>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int type[4] = {25, 10, 5, 1};
    while (n--)
    {
        int m;
        std::cin >> m;

        for (int c : type)
        {
            std::cout << m / c << " ";
            m %= c;
        }
    }

    return 0;
}
