#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> coin(N);
    for (int i = N - 1; i >= 0; i--)
        std::cin >> coin[i];
    
    int count = 0;
    int i = 0;
    while (K && i < N)
    {
        int div = K / coin[i];
        // i 동전으로 나눌 수 있다면
        if (div > 0)
        {
            count += div;
            // 나누고 남은 나머지
            K = K % coin[i];
        }
        i++;
    }

    std::cout << count;
    

    return 0;
}