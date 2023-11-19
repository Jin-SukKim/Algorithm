#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;
    while (idx < progresses.size()) {
        for (int i = 0; i < progresses.size(); i++)
            if (progresses[i] < 100)
                progresses[i] += speeds[i];
        
        int cnt = 0;
        while (idx < progresses.size() && progresses[idx] > 99) {
            cnt++;
            idx++;
        }
        
        if (cnt > 0)
            answer.push_back(cnt);
    }
    
    return answer;
}