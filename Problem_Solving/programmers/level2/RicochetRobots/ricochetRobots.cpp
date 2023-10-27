#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int col = 0;
    int row = 0;
    int count = 0;
};


// 시작 위치
Pos InitialPos(vector<string>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].length(); j++)
            if (board[i][j] == 'R')
                return {i , j};
    }
    return {0, 0};
}

bool Check(const int col, const int row, const int& height, const int& width)
{
    if (col < 0 || row < 0 || col >= height || row >= width)
        return false;
    return true;
}

int Movement(vector<string>& board, Pos& initial) {
    // 상, 하, 좌, 우 4 방향 중 다음 움직임
    int NextCol[4] = {-1, 1, 0, 0};
    int NextRow[4] = {0, 0, -1, 1};
    
    queue<Pos> q;
    q.push(initial);
    
    int width = board[0].length(), height = board.size();
    // 방문 표시
    board[initial.col][initial.row] = '#';
    
    while (!q.empty())
    {
        auto [col, row, count] = q.front();
        q.pop();
        
        if (board[col][row] == 'G')
            return count;
        
        for (int i = 0; i < 4; i++)
        {
            int nCol = col;
            int nRow = row;
            
            // 미끄러지듯이 움직여 보드 끝이나 벽(D)에 부딪히면 멈춘다.
            while (Check(nCol, nRow, height, width) && board[nCol][nRow] != 'D') {
                nCol += NextCol[i];
                nRow += NextRow[i];
            }
            
            // 멈춘 위치
            nCol -= NextCol[i];
            nRow -= NextRow[i];
                
            if (board[nCol][nRow] != '#')
            {
                if (board[nCol][nRow] != 'G')
                    board[nCol][nRow] = '#';
                q.push({nCol, nRow, count + 1});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    Pos initial = InitialPos(board);
    
    answer = Movement(board, initial);
    
    return answer;
}

int main()
{
    solution({"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."});
    return 0;
}