#include <iostream>
#include <vector>
#include <cmath>
struct Point
{
    // 좌표
    int x;
    int y;
};

struct Planet
{
    // 중점
    int x;
    int y;
    // 반지름
    int r;
};

int orbit(std::vector<Point> spaceship, int n)
{
    int count = 0;
    while (n--)
    {
        Planet p;
        std::cin >> p.x >> p.y >> p.r;

        // 원의 중점에서 r만큼 떨어진 점(p) sqrt(pow(p.x - x) + pow(p.y - y)) = r
        // = pow(p.x - x) + pow(p.y - y) = r^2
        // 출발점이나 도착점이 행성 내부에 위치한 경우 진입/이탈 횟수가 추가된다.
        
        // 출발점과 원의 중점과의 거리
        int d1 = std::pow(spaceship[0].x - p.x, 2) + std::pow(spaceship[0].y - p.y, 2);
        // 도착점과 원의 중점과의 거리
        int d2 = std::pow(spaceship[1].x - p.x, 2) + std::pow(spaceship[1].y - p.y, 2);
        // 원의 반지름
        int r = p.r * p.r;

        // 출발점이 밖에 있고 도착점이 안에 있다면 진입
        if (d1 > r && d2 < r)
            count++;
        // 출발점이 안에 있고 도착점이 밖에 있다면 이탈
        else if (d1 < r && d2 > r)
            count++;
    }
    return count;
}

int main()
{
    int T;
    std::cin >> T;

    std::vector<Point> spaceship(2);
    while (T--)
    {
        Point p1, p2;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        spaceship[0] = p1;
        spaceship[1] = p2;

        int n;
        std::cin >> n;
        std::cout << orbit(spaceship, n) << std::endl;
    }
}