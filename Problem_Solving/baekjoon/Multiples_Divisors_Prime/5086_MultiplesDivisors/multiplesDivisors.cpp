#include <iostream>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);

    while (1)
    {
        int n, m;
        std::cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        if (m % n == 0)
            std::cout << "factor" << "\n";
        else if (n % m == 0)
            std::cout << "multiple" << "\n";
        else
            std::cout << "neihter" << "\n";

    }


    return 0;
}
