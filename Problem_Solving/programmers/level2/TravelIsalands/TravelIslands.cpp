#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Island {
    int col;
    int row;
};

int IslandsDays(vector<string>& maps, const int& sCol, const int& sRow, const int& h, const int& w)
{
    int NextCol[4] = {-1, 1, 0, 0};
    int NextRow[4] = {0, 0, -1, 1};
    
    int days = maps[sCol][sRow] - '0';
    
    queue<Island> q;
    q.push({sCol, sRow});
    maps[sCol][sRow] = 'X';
    
    while (!q.empty())
    {
        Island cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nCol = cur.col + NextCol[i];
            int nRow = cur.row + NextRow[i];
            
            if (nCol < 0 || nRow < 0 || nCol >= h || nRow >= w || maps[nCol][nRow] == 'X')
                continue;
            
            days += maps[nCol][nRow] - '0';
            q.push({nCol, nRow});
            maps[nCol][nRow] = 'X';
        }
        
        if (q.empty())
            return days;
    }
    
    return days;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int h = maps.size(), w = maps[0].length();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0 ; j < w; j++) {
            if (maps[i][j] != 'X')
            {
                answer.push_back(IslandsDays(maps, i, j, h, w));
            }
        }
    }
    
    if (answer.empty())
        return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}