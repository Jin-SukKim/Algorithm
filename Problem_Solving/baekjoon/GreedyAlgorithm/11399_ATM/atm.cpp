#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    // 각 사람당 걸리는 시간
    std::vector<int> time(N);

    for (int i = 0; i < N; i++)
        std::cin >> time[i];

    std::sort(time.begin(), time.end());

    // 각 사람당 기다리는 시간
    std::vector<int> wait(N);
    wait[0] = time[0];
    for (int i = 1; i < N; i++)
    {
        wait[i] = time[i] + wait[i - 1];
    }

    // 모든 사람이 걸린 시간
    int sum = 0;
    for (int& i : wait)
        sum += i;
    std::cout << sum;

    return 0;
}