#include <algorithm>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &A, int &N) {
    bool changed = false;
    for (int i = 1; i <= N + 1; i++) {
        changed = false;
        for (int j = 1; j <= N - i; j++) {
            if (A[j] > A[j + 1]) {
                changed = true;
                std::swap(A[j], A[j + 1]);
            }
        }
        // 버블 정렬이 몇번에 끝나는 지
        if (changed == false) {
            std::cout << i << '\n';
            break;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    // 버블 정렬은 왼쪽으로 이동은 못하고 무조건 오른쪽으로 이동한다
    std::sort(A.begin(), A.end());
    // 배열의 몇 번째 index가 정렬된 후 어느 index로 움직였는지 구하면
    // 버블 정렬 횟수를 구할 수 있다.
    // 정렬 전과 정렬 후의 index의 차를 비교해준다.
    // index의 차가 양수이면 swap되며 왼쪽으로 이동한 것이다.
    int maxDiff = 0;
    for (int i = 0; i < N; i++)
    {
        if (maxDiff < A[i].second - i)
            maxDiff = A[i].second - i;
    }
    std::cout << maxDiff + 1;
    return 0;
}