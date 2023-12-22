#include <string>
#include <vector>

using namespace std;
// 문자열, l = 부분 문자의 길이
// 문자열 전체를 일정 크기로 끊어 반복을 찾는 문제
int Zip(const string& s, int l) {
    
    string zip = "";
    int cnt = 1;
    // 문자가 반복되는지 확인할 부분 문자
    string repeat = s.substr(0, l);
    for (int i = l; i < s.length(); i += l) {
        if (repeat == s.substr(i, l))
            cnt++;
        else {
            if (cnt > 1)
                zip += to_string(cnt); // 압축한 부분 문자 개수
            zip += repeat;
            cnt = 1;
            // 문자열은 제일 앞부터 정해진 길이만큼 잘라야 한다.
            // (ex: xabab일때 x / ab / ab는 불가능)
            repeat = s.substr(i, l);
        }
    }
    if (cnt > 1)
        zip += to_string(cnt);
    zip += repeat;
    
    // 압축한 문자열의 길이
    return zip.length();
}

int solution(string s) {
    int answer = s.length();
    
    // 문자를 자를 수 있는 사이즈는 1부터 s의 길이 / 2이다 
    // (s의 길이 / 2보다 큰 부분 문자열은 반복될 수 없다. 만약 반복되면 s의 길이를 넘어선다.)
    for (int i = 1; i <= s.length() / 2; i++)
        answer = min(answer, Zip(s, i));
    return answer;
}