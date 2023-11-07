#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
n	bits	                    length	    # of 1's
0	"1"	                        5^0	        4^0
1	"11011"	                    5^1	        4^1
2	"1101111011000001101111011"	5^2	        4^2
3	"110111101100000110111101111011110110000011011110110000000000000000000000       00011011110110000011011110111101111011000001101111011"	
                                5^3	        4^3      
    n(1 ≤ n) 번째 유사 칸토어 비트열은 n - 1 번째 유사 칸토어 비트열에서의 1을 11011로 치환하고 0을 00000로 치환하여 만듭니다.
    f(0) = 1 // 0 번째 유사 칸토어 비트열은 "1" 입니다.
    f(1) = f(0) = 11011
    f(2) = f(1) + f(1) + "00000" + f(1) + f(1)  
    f(n) = f(n - 1) + f(n - 1) + 0.repeat(5^(n-1)) + f(n - 1) + f(n - 1)
*/
long long BitCount(int n, long long i)
{
    // n = 1, 11011
    if (n == 1)
        return i <= 2 ? i : i - 1;
    
    // n의 길이를 n - 1의 길이로 나누면 일정한 구간별로 구분할 수 있다.
    // n = 2인 경우, n - 1로 나누면 5개의 구간으로 구분된다.
    long long div = pow(5, n - 1);
    // n - 1의 1의 개수, 즉 나눈 구간 별의 1의 개수
    long long ones = pow(4, n - 1);
    // i가 속해있는 구간
    long long section = i / div; 
    long long rem = i % div;
    
    // 11
    if (section < 2)
        return ones * section + BitCount(n - 1, rem);
    // 110
    if (section == 2)
        return ones * section;
    // 11011
    if (section > 2)
        return ones * (section - 1) + BitCount(n - 1, rem);
}


int solution(int n, long long l, long long r) {
    int answer = BitCount(n, r) - BitCount(n, l - 1);
    
    return answer;
}