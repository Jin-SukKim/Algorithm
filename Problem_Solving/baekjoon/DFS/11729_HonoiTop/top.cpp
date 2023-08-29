#include <iostream>

void dfsTop(int n, int start, int mid, int end)
{
    // 탑에 원판이 1개만 있다면 옮겨주면 된다
    if (n == 1)
    {   
        std::cout << start << ' ' << end << '\n';
        return;
    }

    // 제일 무거운 원판을 옮기기 위해 다른 원판들을 가운데 탑으로 옮겨준다.
    dfsTop(n - 1, start, end, mid);
    std::cout << start << ' ' << end << '\n';
    // 가운데 있던 원판들을 다시 마지막 탑으로 옮긴다.
    dfsTop(n - 1, mid, start, end);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    // 하노이 탑의 이동 횟수 2^n - 1
    // shift 연산은 1 칸 이동할 때마다 2배씩 늘어난다.
    std::cout << (1 << N) - 1 << '\n';
    dfsTop(N, 1, 2, 3);

    return 0;
}