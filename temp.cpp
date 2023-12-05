#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
    int x, y, cnt = 0;
}

bool ChkDistance(const vector<string>& places, const int& initX, const int& initY) {
    static int dx[4] = {1, 0, -1, 0};
    static int dy[4] = {0, -1, 0, 1};
    
    bool visited[5][5];
    visited[initY][initX] = true;
    queue<Pos> q;
    q.push({initX, initY, 0});
    
    while (!q.empty())
    {
        auto [x, y, cnt] = q.front();
        q.pop();
        
        if (cnt > 2)
            continue;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if (nx < 0 || ny < 0 || nx > 4 || ny > 4 || visited[ny][nx] || places[ny][nx] == 'X')
                continue;
            
            if (places[ny][nx] == 'P')
                return false;

            visited[ny][nx] = true;
            q.push({nx, ny, cnt + 1});
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
                    keep = ChkDistance(p, j, i);
                
                if (!keep)
                    break;
            }
        }
        answer.push_back(keep);
    }
    
    return answer;
}