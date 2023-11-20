#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long min = 1, max = (long long)n * (*max_element(times.begin(), times.end()));
    long long answer = max;
    
    while (min < max) {
        long long mid = min + (max - min) / 2;
        // 현재 시간 기준 각각 심사대에서 처리하는 사람 수
        long long people = 0;
        for (int& t : times)
            people += mid / t;
        
        if (people < n)
            min = mid + 1;
        else {
            answer = mid < answer ? mid : answer;
            max = mid;
        }
    }
    
    return answer;
}