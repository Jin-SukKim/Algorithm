#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    /*  
        가능한 움직임
        2칸 위로, 1칸 오른쪽
        1칸 위로, 2칸 오른쪽
        1칸 아래로, 2칸 오른쪽
        2칸 아래로, 1칸 오른쪽
    */

    // 세로가 1칸 이면 움직일 수 없다.
    if (N == 1)
        std::cout << 1;
    // 세로가 2칸이면 최대 3번 움직일 수 있따.
    else if (N == 2)
        std::cout << std::min(4, (M + 1) >> 1);
    // 세로가 3칸 이상이면 4개의 움직임이 모두 가능하다.
    else if (N > 2)
    {   
        // 4번 이상 못움직일 때 최대 4칸 이동가능하다
        if (M < 7)
            std::cout << std::min(4, M);
        // 4번 이상 움직일 때 4개의 움직임이 1번 이상 다 나와야 된다.
        else
            std::cout << M -2;
    }

    return 0;
}