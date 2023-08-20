#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    // K가 없을 때 대회에 나갈 수 있는 인원
    int a = std::min(N / 2, M);
    // K명이 인턴쉽으로 빠질때 3명이 대회에 나간다
    int b = (N + M - K) / 3;

    std::cout << std::min(a, b);
    return 0;
}