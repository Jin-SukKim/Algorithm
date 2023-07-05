#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }
    int target;
    std::cin >> target;
    int count = std::count(v.begin(), v.end(), target);
    std::cout << count;

    return 0;
}