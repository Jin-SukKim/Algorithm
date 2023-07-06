#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string s;

    while (std::getline(std::cin, s))
    {
        std::cout << s << "\n";
    }
    return 0;
}


