#include <string>
#include <vector>

using namespace std;

void bfs(vector<int>& numbers, int& cnt, int sum, int idx, int target) {
    if (idx >= numbers.size()) {
        if (sum == target)
            ++cnt;
        return;
    }
    bfs(numbers, cnt, sum + numbers[idx], idx + 1, target);
    bfs(numbers, cnt, sum - numbers[idx], idx + 1, target);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    bfs(numbers, answer, 0, 0, target);
    
    return answer;
}