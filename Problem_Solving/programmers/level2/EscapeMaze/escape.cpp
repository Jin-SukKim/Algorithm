#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int col;
    int row;
    int sec = 0;
};

Pos InitialPos(const vector<string>& maps)
{
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].length(); j++)
            if (maps[i][j] == 'S')
                return {i , j};
    }
    return {0, 0};
}

Pos MoveToDest(const vector<string>& maps,const Pos& start, const char& dest)
{
    // 상, 하, 좌, 우 움직임
    int NextCol[4] = {1, -1, 0, 0};
    int NextRow[4] = {0, 0, -1, 1};
    
    // 시작 위치
    queue<Pos> q;
    q.push(start);
    
    int height = maps.size(), width = maps[0].length();
    // 방문한 곳
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    
    while (!q.empty())
    {
        Pos curPos = q.front();
        q.pop();
        
        if (maps[curPos.col][curPos.row] == dest)
            return curPos;
        
        for (int i = 0; i < 4; i++)
        {
            int nCol = curPos.col + NextCol[i];
            int nRow = curPos.row + NextRow[i];
            
            if (nCol < 0 || nRow < 0 || nCol >= height || nRow >= width || maps[nCol][nRow] == 'X' || visited[nCol][nRow])
                continue;
            
            visited[nCol][nRow] = true;
            q.push({nCol, nRow, curPos.sec + 1});
        }
    }
    
    return {-1, -1, -1};
}


int solution(vector<string> maps) {
    Pos pos = InitialPos(maps);
    pos = MoveToDest(maps, pos, 'L');
    if (pos.sec < 0)
        return -1;
    pos = MoveToDest(maps, pos, 'E');
    
    return pos.sec;
}