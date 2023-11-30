#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

// 10진수를 k 진수로 변환
string BaseN(int& n, int& k) {
    string baseN = "";
    
    while (n) {
        int rem = n % k;
        n /= k;
        if (rem > 9)
            // 'A' = 65인데 10부터 A로 변환하므로 A - 10 = 55를 더한다.
            baseN = char(rem + 55) + baseN;
        else
            baseN = to_string(rem) + baseN;
    }
    return baseN;
}

// 소수 판별 함수
bool ChkPrime(string& n) {
    long long p = stol(n);
    
    if (p < 2)
        return false;
    
    // 큰 수도 빠르게 판별하기 위해 i * i <= p까지 확인 (ex: 4 * 4 = 16,으로 최소한으로 확인)
    for (long long i = 2; i * i <= p; i++)
        if (p % i == 0)
            return false;
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    stringstream ss(BaseN(n, k));
    string buffer = "";
    
    // stringstream을 활용해 '0'을 기준으로 나누기
    while (getline(ss, buffer, '0')) 
        if (!buffer.empty() && ChkPrime(buffer))
            answer++;
    
    return answer;
}