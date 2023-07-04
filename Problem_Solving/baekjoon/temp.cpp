#include <iostream>
int main()
{
    std::cin.tie(nullptr); // cin만 풀어줘 입력을 먼저 한 번에 다 받는다.
    std::ios_base::sync_with_stdio(false);
    int T, a, b;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::cin >> a >> b;
        std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
    }
    return 0;
}
