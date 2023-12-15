#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

// string의 1의 개수
int Convert(string& b) {
    int one = 0;
    for (char& c : b) 
        if (c == '1')
            one++;
    
    return one;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while (s != "1") {
        answer[0]++;
        int one = Convert(s);
        // 0의 개수
        answer[1] += s.length() - one;
        // 숫자를 2진수 bit로 변환 후 string으로 변환
        s = std::bitset<32>(one).to_string();
        // 총 32bit짜리 2진수로 변환했으므로 앞의 0을 지워준다.
        s.erase(0, s.find_first_not_of('0'));
    } 
    
    return answer;
}