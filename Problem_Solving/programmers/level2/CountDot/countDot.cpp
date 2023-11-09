#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 그래프를 원의 1사분면이라 생각
long long solution(int k, int d) {
    long long answer = 0;
    
    // 원점에서 반지름 값은 항상 동일 (d 값이 크기에 변환)
    const long long d2 = (long long)d * d;
    for (long long x = 0; x <= d; x += k) {
        // 피타고라스 법칙을 활용해 y의 높이를 구한다.
        long long y = d2 - x * x;
        
        answer += (long long)sqrt(y) / k + 1;
    }
    
    return answer;
}