#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::vector<int> v(9);

    for (int i = 0; i < 9; i++)
    {
        std::cin >> v[i];
    }
    
    auto iter = std::max_element(v.begin(), v.end());
    std::cout << *iter << "\n";
    std::cout << iter - v.begin() + 1;
    return 0;
}