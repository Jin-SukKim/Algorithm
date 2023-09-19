#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool checkPrime(int n) {
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i < n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << checkPrime(121) << std::endl;
    std::cout << checkPrime(144) << std::endl;
    std::cout << checkPrime(169) << std::endl;
    std::cout << checkPrime(225) << std::endl;

    return 0;
}