#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int a, b;
    while (1)
    {
        std::cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        std::cout << a + b << std::endl;
    }
    return 0;
}