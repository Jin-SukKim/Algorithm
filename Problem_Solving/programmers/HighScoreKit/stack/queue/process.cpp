#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int Priority = 0;
    int Index = 0;
};

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    queue<Process> q;
    for (int i = 0; i < priorities.size(); i++) 
        q.push({priorities[i], i});
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    for (int i = 0; i < priorities.size(); i++)
    {
        while (q.front().Priority < priorities[i])
        {
            q.push(q.front());
            q.pop();
        }
        
        if (location == q.front().Index)
            return i + 1;
        q.pop();
    }
    
    return answer;
}