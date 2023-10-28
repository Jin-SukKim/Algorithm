#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// 피타고라스의 법칙을 응용해 가장 긴 변의 길이의 제곱을 구해주면 되는 문제
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    // x, y좌표의 거리차를 제곱하여 거리를 구해가장 작은 거리를 고른다.
    // 오른쪽과 아래쪽은 튕기는 방향이 x, y좌표만큼이 아닌 벽에서 x 혹은 y 값을 뺸 만큼 진행
    for (auto& b : balls) {
        int distance = INT_MAX;
        // 각 벽에 쿠션을 넣을 때
        // 왼쪽
        if (startX != b[0] || startY <= b[1])
            distance = min(distance, (int)(pow(startX - b[0], 2) + pow(startY + b[1], 2)));
        // 오른쪽
        if (startX != b[0] || startY >= b[1])
            distance = min(distance, (int)(pow(startX - b[0], 2) + pow(2 * n - startY - b[1], 2)));
        // 아래쪽
        if (startX >= b[0] || startY != b[1])
            distance = min(distance, (int)(pow(2 * m - startX - b[0], 2) + pow(startY - b[1], 2)));
        // 위쪽
        if (startX <= b[0] || startY != b[1])
            distance = min(distance, (int)(pow(startX + b[0], 2) + pow(startY - b[1], 2)));
        answer.push_back(distance);
    }
    
    return answer;
}