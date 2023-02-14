/*
    현재값을 가리키는 포인터가 우측으로 이동하며
    이전 상태의 저점을 기준으로 가격 차이를 계산하고
    이득이 클 수록 최댓값을 교체해가는 형태이다.
    저점도 현재값을 가르키는 포인터까지 나온 최솟값을 유지하도록
    최솟값으로 계속 교체해준다.
*/

#include <vector>
#include <algorithm>

// 114ms, 93.4MB (fast)
int maxProfit(std::vector<int> &prices)
{   
    // 여기서 int에서 가능한 최솟값으로 할 수 있지만 만약
    // 입력값이 없을 경우 -__INT_MAX__가 return될 수도 있기에 0으로 설정했다.
    int profit = 0; // 현재 이득
    int minPrice = __INT_MAX__; // maximum number of possible int

    for (int i : prices) {
        // 저점 갱신하기
        minPrice = std::min(minPrice, i);
        // 최대의 이익을 얻기위해 i의 값에 갱신된 저점을 뺀 이익과
        // 이전의 저점과 i 값에서 얻은 이득 중 더 큰 이득을 구하기
        profit = std::max(profit, i - minPrice);
    }

    return profit;
}