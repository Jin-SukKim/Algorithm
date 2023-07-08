#include <iostream>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    // 정사각형의 개수는 2^i 로 2배씩 상승한다.
    int square = std::pow(2,n);
    // 한 행의 윗변 기준으로 점의 개수는 (정사각형의 개수 + 1)^2 개수이다.
    int dot = std::pow(square + 1, 2);
    std::cout << dot;
    return 0;
}
