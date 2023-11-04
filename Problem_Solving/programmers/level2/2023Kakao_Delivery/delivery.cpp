#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int drop = 0;
    int pick = 0;
    for (int i = n - 1; i > -1; i--)
    {
        if (deliveries[i] || pickups[i])
        {
            int count = 0;
            
            drop -= deliveries[i];
            pick -= pickups[i];
            
            // 만약 최대 적재량만큼 실었는데도 
            // 배달/수거해야될 박스가 남았다면
            while (drop < 0 || pick < 0) {
                drop += cap;
                pick += cap;
                count++; // 같은 장소를 여러번 와야되므로
            }
            
            // 왕복해야 되므로 * 2
            answer += (i + 1) * 2 * count;
        }
    }
    
    return answer;
}