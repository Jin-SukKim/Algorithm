#include <algorithm>
#include <iostream>
#include <vector>

// 종이가 전부 같은 수로되어 있는지 확인
bool check(std::vector<int> &paper, int &N, int &col, int &row, int &size) {
    int num = paper[row + N * col];

    for (int j = col; j < col + size; j++)
        for (int i = row; i < row + size; i++)
            if (paper[i + N * j] != num)
                return false;

    return true;
}

void dividePaper(std::vector<int> &paper, int *count, int &N, int col, int row,
                 int size) {
    if (check(paper, N, col, row, size))
        // 같은 숫자로 채워진 종이 count + 1
        count[paper[row + N * col]]++;
    else {
        // 종이를 9 조각 내야되므로 한 변의 길이를 3으로 나누면 된다.
        size /= 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                dividePaper(paper, count, N, col + size * i, row + size * j,
                            size);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> paper(N * N);
    for (int i = 0; i < N * N; i++) {
        int n;
        std::cin >> n;
        // -1, 0, 1을 0, 1, 2로 정답을 배열로 저장하기 쉽게 바꿔준다.
        paper[i] = n + 1;
    }

    int count[3] = {0};
    dividePaper(paper, count, N, 0, 0, N);
    for (int &i : count)
        std::cout << i << '\n';
    return 0;
}