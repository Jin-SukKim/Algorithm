#include <iostream>
#include <cmath>

struct Player
{
    int x;
    int y;
    int r;
};

// 두 점 사이의 거리 = sqrt(pow(x1 - x2) + pow(y1 - y2))
int distance(Player &p1, Player &p2)
{
    return std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
}
int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        Player player1, player2;
        std::cin >> player1.x >> player1.y >> player1.r >>
            player2.x >> player2.y >> player2.r;

        int d = distance(player1, player2);
        int cond1 = std::pow(player1.r + player2.r, 2);
        int cond2 = std::pow(player1.r - player2.r, 2);

        // 두 터렛의 위치가 같을 떄(동심원)
        if (!d)
        {
            //  터렛이 감지하는 원의 크기가 같다면 무한대
            if (player1.r == player2.r)
                std::cout << -1 << std::endl;
            // 터렛의 원의 크기가 다르다면 두 원이 맞닿을일 이 없어 0
            else
                std::cout << 0 << std::endl;
        }
        else
        {
            // 두 원이 접하고 있을 때 가능한 적의 위치는 1개(내접, 외접)
            if (cond1 == d || cond2 == d)
                std::cout << 1 << std::endl;
            // 두 원이 두 점에서 만난다면
            else if (cond2 < d && d < cond1)
                std::cout << 2 << std::endl;
            // 두 원이 만나지 않는다면
            else
                std::cout << 0 << std::endl;
        }
    }
    return 0;
}