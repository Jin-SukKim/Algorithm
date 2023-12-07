#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long n : numbers) {
        long long bit = 1;
        // 짝수는 마지막 bit가 0이므로 맨 뒤를 1로만 바꿔주면 된다.
        // 홀수는 0인 bit를 찾아 1로 바꿔준 뒤 그 이전 bit를 0으로 바꿔준다.
        while (n & bit) 
            bit <<= 1;
        answer.push_back((n | bit) - (bit >> 1));
    }
    return answer;
}