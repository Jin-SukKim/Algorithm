#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> list(scoville.begin(), scoville.end());
    
    while (list.top() < K) {
        // 만들 수 없는 경우
        if (list.size() < 2)
            return -1;
        
        int min1 = list.top();
        list.pop();
        list.push(min1 + list.top() * 2);
        list.pop();
        answer++;
    }
    
    return answer;
}