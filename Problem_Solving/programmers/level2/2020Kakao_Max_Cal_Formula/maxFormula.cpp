#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calNum(const long long& n1, const long long& n2, const char& op) {
    if (op == '+')
        return n1 + n2;
    if (op == '-')
        return n1 - n2;
    return n1 * n2;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> operand;
    vector<char> op;
    vector<char> priority = {'*', '+', '-'};
    string temp = "";
    // 숫자와 연산자 분리
    for (char& c : expression) {
        if (c >= '0' && c <= '9') 
            temp += c;
        else {
            operand.push_back(stoll(temp));
            op.push_back(c);
            temp = "";
        }
    }
    // 마지막 숫자
    operand.push_back(stoll(temp));
    
    do {
        vector<long long> temp_operand = operand;
        vector<char> temp_op = op;
        for (char& o : priority) {
            for (int i = 0; i < temp_op.size();) {
                // 계산한 뒤 연산자를 삭제하니 for loop에서 i++ 해주지 않고 다르다면 +1해준다.
                if (o == temp_op[i]) { // 현재 우선순위 연산자라면
                    long long cal = calNum(temp_operand[i], temp_operand[i + 1], temp_op[i]);
                    // 계산한 숫자 두개 삭제
                    temp_operand.erase(temp_operand.begin() + i, temp_operand.begin() + i + 2);
                    temp_op.erase(temp_op.begin() + i);
                    // 계산한 결과 삽입
                    temp_operand.insert(temp_operand.begin() + i, cal);
                } else
                    i++;
            }
        }
        // 최종적으로 temp_operand에 숫자 하나만 남는다.
        answer = max(answer, abs(temp_operand[0]));
    } while (next_permutation(priority.begin(), priority.end())); // 다음 조합
    
    return answer;
}