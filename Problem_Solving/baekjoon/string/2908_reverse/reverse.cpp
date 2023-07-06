#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string a, b;
    std::cin >> a >> b;

    std::reverse(a.begin(),a.end());
    std::reverse(b.begin(),b.end());

    int res = a > b ? std::stoi(a) : std::stoi(b);
    std::cout << res;
    return 0;
}