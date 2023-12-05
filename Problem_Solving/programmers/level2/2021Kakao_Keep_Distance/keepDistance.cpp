#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
    unsigned int x, y, dist = 0;
};

bool ChkDistance(const vector<string>& places, const unsigned int& initX, const unsigned int& initY) {
    static const int dx[4] = {1, 0, -1, 0};
    static const int dy[4] = {0, -1, 0, 1};
    
    bool visited[5][5] = { false, };
    queue<Pos> q;
    
    visited[initY][initX] = true;
    q.push({initX, initY, 0});
    
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        
        if (cur.dist > 1)
            continue;
        
        for (int i = 0; i < 4; i++) {
            unsigned int nx = cur.x + dx[i];
            unsigned int ny = cur.y + dy[i];
                
            // unsigned int로 범위를 벗어나 음수가 되면 큰 수가 된다.
            if (nx > 4 || ny > 4 || visited[ny][nx] || places[ny][nx] == 'X')
                continue;
            
            if (places[ny][nx] == 'P')
                return true;

            visited[ny][nx] = true;
            q.push({nx, ny, cur.dist + 1});
        }
    }
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string>& p : places) {
        bool keep = true;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) { 
                if (p[i][j] == 'P' && ChkDistance(p, j, i)) {
                    keep = false;
                    break;
                }
            }
        }
        answer.push_back(keep);
    }
    
    return answer;
}