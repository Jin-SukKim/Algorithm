#include <string>
#include <vector>

using namespace std;

bool EndCondition(const vector<string>& board, const char& p)
{
    // 가로, 세로 방향으로 이긴 조건이 있는지 확인
    for (int i = 0; i < 3; i++)
    {
        int col = 0, row = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == p)
                row++;
            if (board[j][i] == p)
                col++;
        }
        
        if (col == 3 || row == 3)
            return true;
    }
    
    // 대각선 조건 확인
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int x = 0, o = 0;
    for (const string& s : board) {
        for (const char& c : s)
        {
            if (c == 'O')
                o++;
            else if (c == 'X')
                x++;
        }
    }
    
    // x가 많거나 O가 2개 이상 더 많은 경우는 존재할 수 없다.
    if (o < x || o - x > 1)
        return 0;
    
    bool oEnd = false, xEnd = false;
    if (o > 2)
        oEnd = EndCondition(board, 'O');
    
    if (x > 2)
        xEnd = EndCondition(board, 'X');
    
    // 둘 다 이긴 경우
    // O가 이겼지만 O가 1개 더 많지 않은 경우
    // x가 이겼지만 o와 x의 개수가 같지 않은 경우
    if ((oEnd && xEnd) || (oEnd && o - x != 1) || (xEnd && o != x))
        return 0;
    
    return 1;
}