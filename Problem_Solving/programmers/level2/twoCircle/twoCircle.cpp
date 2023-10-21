#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long R1 = (long long)r1 * r1;
    long long R2 = (long long)r2 * r2;
    
    // 1 사분면에서 구할 수 있는 점의 개수
    for (long long x = 1; x <= r2; x++)
    {
        // 원의 방정식 x^2 + y^2 = r^2;
        // y = sqrt(r^2 - x^2), y의 길이
        long long x2 = x * x;
        // 정수값만 원하므로 버림, 올림 사용
        long long minY = ceil(sqrt(R1 - x2));
        long long maxY = floor(sqrt(R2 - x2));
        
        if (r1 < x)
            minY = 0;
        
        answer += maxY - minY + 1;
    }
    return answer * 4;
}