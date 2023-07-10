#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(false);

    int V, A, B;
    std::cin >> A >> B >> V;

    int day = 0;

    // 목표까지의 거리가 낮의 이동거리보다 같거나 작으면 하루면 된다.
    if (V <= A)
    {
        std::cout << "1";
        return 0;
    }

    // 목표 V가 아닌 V - A까지만 가면 다음날 아침에 A 만큼 올라서 정상에 갈 수 있다.
    // 결국 V - A까지 가는데 걸리는 기간은 (V - A) / (A - B)이다.
    // 나머지가 0 인 경우 마지막날 A만큼 오르면 되지만,
    if ((V - A) % (A - B) == 0)
        
        day = (V - A) / (A - B);
    // 나머지가 0이 아닌 경우 이동거리가 모자라므로 하루 더 움직여야 V - A에 도착할 수 있다.
    else
        day = (V - A) / (A - B) + 1;

    // V - A까지 도착했으므로 마지막날 A만큼 올라준다.
    std::cout << day + 1;
    return 0;
}
