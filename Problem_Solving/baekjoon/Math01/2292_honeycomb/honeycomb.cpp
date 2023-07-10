#include <iostream>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);

    int level = 1;

    int dest;
    std::cin >> dest;
    
    int room = 1;
    while (1)
    {
        if (dest <= room)
            break;

        // 벌집의 중앙에서 한 층씩 밖으로 갈때마다 방의 개수가
        // 이전 층의 방의 개수에 +6 식 증가한다. 1, 2-7(6개), 8-19(12개), 20-37(18개)
        // 결국 각 층은 6 * i(층)개의 방의 개수로 이루어져 있다.
        room += level * 6;
        level++;
    }

    std::cout << level;
    return 0;
}
