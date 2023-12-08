#include <string>
#include <vector>
using namespace std;


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // 시계 반대 방향 회전
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    vector<vector<int>> map(rows + 1, vector<int>(columns + 1, 0));
    for (int i = 1; i <= rows; i++) 
        for (int j = 1; j <= columns; j++)
            map[i][j] = j + (i - 1) * columns;
    
    for (vector<int>& q : queries) {
        int nDir = 0; // 오른쪽 방향
        int row = q[0];
        int col = q[1];
        int begin = map[row][col];
        int minNum = begin;
        
        // 회전이 끝나는 지점에 도착할 때 까지
        while (row != q[0] || col != q[1] + 1) {
            if (row == q[2] && col == q[1])
                nDir++; 
            else if (row == q[2] && col == q[3])
                nDir++; 
            else if (row == q[0] && col == q[3])
                nDir++; 
            
            map[row][col] = map[row + dir[nDir][0]][col + dir[nDir][1]];
            row += dir[nDir][0];
            col += dir[nDir][1];
            minNum = min(minNum, map[row][col]);
        }
        
        map[row][col] = begin;
        minNum = min(minNum, begin);
        answer.push_back(minNum);
    }
    return answer;
}