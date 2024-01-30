#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool Check(const vector<string>& board, const int& row, const int& col) {
    for (int i = row; i < row + 2; ++i) {
        for (int j = col; j < col + 2; ++j) {
            if (board[row][col] != board[i][j])
                return false;
        }
    }
    return true;
}

void Remove(vector<string>& board, set<pair<int, int>>& Pairs) {
    for (auto [row, col] : Pairs) {
        if (board[row][col] != '0') 
            board[row][col] = '0';
    }
}

void Reorder(const int& m, const int& n, vector<string>& board) {
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '0') {
                // '0' 위의 모든 블록을 한칸씩 아래로 내린다.
                for (int k = i; k > 0; k--) {
                    if (board[k - 1][j] == '0')
                        break;
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = '0';
                }
            }
        }
    }
}

int Phase(const int& m, const int& n, vector<string> board) {
    set<pair<int, int>> Pairs;

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            // 2x2 블록 찾기
            if (board[i][j] != '0' && Check(board, i, j)) {
                Pairs.insert({ i, j });
                Pairs.insert({ i, j + 1 });
                Pairs.insert({ i + 1, j });
                Pairs.insert({ i + 1, j + 1 });
            }
        }
    }

    if (Pairs.empty()) {
        return 0;
    }
    else {
        // 지워질 블록이 존재한다면
        Remove(board, Pairs); // 삭제
        Reorder(m, n, board); // 재정리

        return Pairs.size() + Phase(m, n, board);
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    answer = Phase(m, n, board);

    return answer;
}
