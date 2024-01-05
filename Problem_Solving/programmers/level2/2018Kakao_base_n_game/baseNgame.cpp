#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ConvertToBase(int num, const int& base) {
    static char List[] = {'0', '1', '2', '3', '4', '5', '6','7','8','9','A','B','C','D','E','F'};
    string baseNum = "";
    
    if (!num) 
        return "0";
    
    while (num) {
        baseNum += List[num % base];
        num /= base;
    }
    reverse(baseNum.begin(), baseNum.end());
    return baseNum;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int i = 0;
    string nums = "";
    // m 명이 돌아가며 한 숫자씩 말할 때 t번 말하려면 t * m보다는 긴 수여야한다.
    while (nums.length() <= t * m) 
        nums += ConvertToBase(i++, n);
    
    i = p - 1; // 시작 위치
    while (answer.length() < t) {
        answer += nums[i];
        i += m;
    }
    
    return answer;
}