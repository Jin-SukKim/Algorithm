#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
    int x, y, dist = 0;
};

bool ChkDistance(const vector<string>& places, const int& initX, const int& initY) {
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
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
                
            if (nx < 0 || ny < 0 || nx > 4 || ny > 4 || visited[ny][nx] || places[ny][nx] == 'X')
                continue;
            
            if (places[ny][nx] == 'P')
                return false;

            visited[ny][nx] = true;
            q.push({nx, ny, cur.dist + 1});
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string>& p : places) {
        bool keep = true;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) { 
                if (p[i][j] == 'P') 
                    keep &= ChkDistance(p, j, i);
                
                if (!keep)
                    break;
            }
        }
        answer.push_back(keep);
    }
    
    return answer;
}