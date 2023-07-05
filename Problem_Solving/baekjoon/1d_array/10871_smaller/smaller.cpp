#include <iostream>
#include <vector>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, X;
    std::cin >> N >> X;
    std::vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    for (int& elem : v)
    {
        if (elem < X)
            std::cout << elem << " ";
    }
    return 0;
}