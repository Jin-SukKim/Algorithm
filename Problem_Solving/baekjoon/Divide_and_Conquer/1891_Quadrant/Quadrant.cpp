#include <array>
#include <cmath>
#include <iostream>
#include <vector>
class Answer {
    std::string pos;
    long long x, y;
  public:
    long long size;

    Answer(int& d, std::string &startNum, long long &moveX, long long &moveY)
        : size(1LL << d), pos(startNum) {
        get_coordinate(0, 0, 0, this->size);
        // 구할 좌표
        x += moveX;
        y -= moveY;
        pos.clear();
    }

    // 시작하는 위치의 사분면의 숫자로 좌표를 얻는다.
    void get_coordinate(long long col, long long row, long long index, long long size) {
        if (size == 1) {
            x = row;
            y = col;
            return;
        }
        // dfs처럼 다시 돌아갈 필요가 없어 return으로 끝내준다
        if (pos[index] == '1')
            get_coordinate(col, row + size / 2, index + 1, size / 2);
        else if (pos[index] == '2')
            get_coordinate(col, row, index + 1, size / 2);
        else if (pos[index] == '3')
            get_coordinate(col + size / 2, row, index + 1, size / 2);
        else if (pos[index] == '4')
            get_coordinate(col + size / 2, row + size / 2, index + 1, size / 2);
        return;
    }

    void move(long long col, long long row, long long size) {
        if (!isExist())
            return;

        if (size == 1)
            return;
        if (y < col + size / 2 && x < row + size / 2) {
                pos += '2';
                move(col, row, size / 2);
        } else if (y < col + size / 2 && x >= row + size / 2) {
                pos += '1';
                move(col, row + size / 2, size / 2);
        } else if (y >= col + size / 2 && x < row + size / 2) {
                pos += '3';
                move(col + size / 2, row, size / 2);
        } else if (y >= col + size / 2 && x >= row + size / 2){
                pos += '4';
                move(col + size / 2, row + size / 2, size / 2);
        }
        return;
    }

    bool isExist()
    {
        // 범위 밖이라면
        if (x < 0 || x >= size || y < 0 || y >= size) {
            pos = "-1";
            return false;
        }
        return true;
    }

    void print() { std::cout << pos; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int d;
    std::string start;
    long long x, y;

    // 시작하는 사분면 중 위치, 첫 시작 번호
    std::cin >> d >> start;

    // 이동할 좌표
    std::cin >> x >> y;

    Answer a(d, start, x, y);
    a.move(0, 0, a.size);
    a.print();

    return 0;
}