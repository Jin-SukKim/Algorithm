#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    // 체스 피스 : 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
    std::vector<int> chess = {1, 1, 2, 2, 2, 8};    

    for (int i = 0; i < 6; i++)
    {
        // 가진 각 말의 수
        int piece = 0;
        std::cin >> piece;
        // 빼거나 더해줘야 할 각 말의 수
        chess[i] -= piece;
    }

    for (int& piece : chess)
        std::cout << piece << " ";

    return 0;
}


