#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> disk;
    
    int work = 0, time = 0;
    while (work < jobs.size() || !disk.empty()) {
        if (work < jobs.size() && jobs[work][0] <= time) {
            disk.push(jobs[work++]);
            continue;
        }
        
        // 작업 수행
        if (!disk.empty()) {
            time += disk.top()[1];
            // 작업시간 + 대기시간 = 현재 시간 - 들어온 시간
            answer += time - disk.top()[0];
            disk.pop();
        } 
        // 수행할 작업이 없고 현재 시간에 들어올 작업이 없으면 다음 작업 시간으로 간다.
        else 
            time = jobs[work][0];
    }
    
    return answer / jobs.size();
}