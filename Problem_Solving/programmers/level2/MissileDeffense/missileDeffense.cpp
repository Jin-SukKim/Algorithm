#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    int end = 0;
    for (auto v : targets)
    {
        // 미사일의 끝 좌표가 다른 미사일의 시작 좌표보다 작거나 같다면
        // 한번에 요격할 수 없다는 의미이므로 갱신
        if (end <= v[0])
        {
            end = v[1];
            answer++;
        }
    }
    
    
    
    return answer;
}