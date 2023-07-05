#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    // 0으로 배열을 초기화
    std::vector<int> v(N, 0);

    while (M--)
    {
        int i, j, k;
        std::cin >> i >> j >> k;
        // i번부터 j번 element까지 숫자를 삽입/교체
        for (; i <= j; i++)
        {
            v[i-1] = k;
        }
    }

    for (int& i: v)
        std::cout << i << " ";
    return 0;
}