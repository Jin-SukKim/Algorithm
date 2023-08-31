#include <array>
#include <cmath>
#include <iostream>
#include <vector>
class Answer {
    int N, r, c;
    int count = 0;

  public:
    Answer(int N, int r, int c) : N(N), r(r), c(c) {}

    void zGraph(int col, int row, int size) {
        if (col == c && row == r) {
            std::cout << count;
            exit(0);
        }

        else if (c < col + size && r < row + size && c >= col && r >= row) {
            // 4 분할
            int half = size / 2;
            zGraph(col, row, half);
            zGraph(col + half, row, half);
            zGraph(col, row + half, half);
            zGraph(col + half, row + half, half);
        }
        else
            // 없으면 사각형의 크기가 카운트 4 분할 카운트한 숫자이다.
            count += size * size;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, r, c;
    std::cin >> N >> r >> c;

    Answer a(N, r, c);
    a.zGraph(0, 0, (1 << N));
    return 0;
}