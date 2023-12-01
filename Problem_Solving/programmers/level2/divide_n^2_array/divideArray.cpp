#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // 2d array를 1d array로 표현
    for (long long i = left; i <= right; i++) {
        long long row = i / n;
        long long col = i % n;
        
        if (row < col)
            answer.push_back(col + 1);
        else
            answer.push_back(row + 1);
    }
    
    
    return answer;
}