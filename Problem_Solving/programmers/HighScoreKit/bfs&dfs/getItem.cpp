#include <string>
#include <vector>
#include <queue>

using namespace std;

int FindPath(vector<vector<int>>& map, const int& cX, const int& cY, const int& itemX, const int& itemY) {
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> p;
    p.push({cX, cY});
    
    while (!p.empty()) {
        auto [x, y] = p.front();
        p.pop();
        
        if (x == itemX && y == itemY)
            return map[y][x];
        
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dirX[i];
            int nextY = y + dirY[i];
            
            if (nextX < 0 || nextY < 0 || nextX > 102 || nextY > 102 || map[nextY][nextX] != 1)
                continue;
            
            map[nextY][nextX] += map[y][x];
            p.push({nextX, nextY});
        }
    }
    
    return map[itemY][itemX];
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    // 좌표는 최대 50
    vector<vector<int>> map(102, vector<int>(102, 0));
    
    for (vector<int>& rect : rectangle) {
        // 좌표가 너무 가까우면 두 변이 서로 연결되므로 크기를 2배로 키운다.
        for (int i = 0; i < 4; i++)
            rect[i] *= 2;
        
        // 사각형을 map에서 1로 지정 (길)
        for (int i = rect[1]; i <= rect[3]; i++)
            for (int j = rect[0]; j <= rect[2]; j++)
                map[i][j] = 1;
    }
    
    
    for (vector<int>& rect : rectangle) {
        // 사각형 내부를 0으로 바꿔 겹치지 않는 테두리만 1로 되게 한다.
        // 사각형 내부 테두리 중 1이 남아도 주변 테두리와 연결이 끊겨 있어 못간다.
        for (int i = rect[1] + 1; i < rect[3]; i++)
            for (int j = rect[0] + 1; j < rect[2]; j++)
                map[i][j] = 0;
    }
    
    answer = FindPath(map, characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer / 2;
}