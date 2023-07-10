#include <iostream>
#include <cmath>
int main()
{
    std::ios_base::sync_with_stdio(false);

    int diagonol = 0;

    int N;
    std::cin >> N;

    // N이 몇 번째 대각선에 위치하는 지 구해준다.
    // 1번째 대각선엔 1개, 2번째 대각선까지 3개, 3번째 대각선에 6개씩 분수들이 있다.
    // 3번째 대각선 분수 개수 = 1 + 2 + 3, I 번째 대각선의 분수 개수 = 1 + 2 + ... + i
    while (N > 0)
    {   
        diagonol++;
        N -= diagonol;
    }

    // 대각선이 홀수번째인지 짝수번째인지에 따라 분모와 분자의 위치가 달라진다.
    // N은 결국 대각선의 반대 방향에서 시작해 지정된 위치의 -index 값이 된다.
    // 2는 2번째 대각선의 반대 방향에서 시작한 -index값이므로 -1이 되고
    // 3은 2번째 대각선의 반대 방향에서 시작한 첫 index이므로 0이된다. 
    if (diagonol % 2) // 홀수
        std::cout << 1 - N << "/" << diagonol + N;
    else // 짝수
        std::cout << diagonol + N << "/" << 1 - N;
    return 0;
}
