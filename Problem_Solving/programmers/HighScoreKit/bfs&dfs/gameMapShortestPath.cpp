#include<vector>
#include <queue>
#include <iostream>

using namespace std;

int FindPath(vector<vector<int>>& maps) {
    // 상하좌우 1칸씩 이동
    int nextCol[4] = {-1, 1, 0 ,0};
    int nextRow[4] = {0, 0, -1, 1};
    
    int n = maps.size(), m = maps[0].size();
    queue<pair<int, int>> p;
    p.push({0, 0});
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[0][0] = 1;
    
    while (!p.empty())
    {
        // 현재 위치
        auto [col, row] = p.front();
        p.pop();
        
        if (col == (n - 1) && row == (m - 1))
            return visited[col][row];
        
        for (int i = 0; i < 4; i++)
        {
            // 다음 위치 (1칸씩 이동)
            int nextC = col + nextCol[i];
            int nextR = row + nextRow[i];
            
            // 맵 범위 밖, 이미 방문한 곳, 벽
            if (nextC < 0 || nextR < 0 || nextC >= n || nextR >= m || visited[nextC][nextR] || !maps[nextC][nextR])
                continue;
            
            p.push({nextC, nextR});
            visited[nextC][nextR] += visited[col][row] + 1;
        }
    }
    
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return FindPath(maps);;
}