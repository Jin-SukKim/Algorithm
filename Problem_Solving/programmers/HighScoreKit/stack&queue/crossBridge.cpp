#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    // 다리 길이만큼 0으로 채워준다.
    for (int i = 0; i < bridge_length; i++)
        bridge.push(0);
    
    int cnt = 0;
    int idx = 0;
    while (cnt != truck_weights.size())
    {
        weight += bridge.front();
        // 트럭이 다리를 건넜으면
        if (bridge.front())
            cnt++;
        
        bridge.pop();
        
        // 트럭이 다리 위로 못 올라갈 때
        if (weight < truck_weights[idx])
            bridge.push(0);
        // 트럭이 다리위로 올라갈 때
        else {
            weight -= truck_weights[idx];
            bridge.push(truck_weights[idx]);
            idx++;
        } 
        
        answer++;
    }
    
    return answer;
}