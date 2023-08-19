#include <iostream>
#include <queue>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    // 보석 = {무게, 가격}
    std::vector<std::pair<int, int>> jewels(N);
    for (int i = 0; i < N; i++)
        std::cin >> jewels[i].first >> jewels[i].second;

    std::vector<int> bags(K);
    for (int i = 0; i < K; i++)
        std::cin >> bags[i];

    std::sort(jewels.begin(), jewels.end());
    std::sort(bags.begin(), bags.end());

    // 가격을 비교해 비싼 것부터 넣을 수 있도록 한다.
    std::priority_queue<std::pair<int, int>> j;

    long long cost = 0;
    int index = 0;
    for (int i = 0; i < K; i++) {
        // 가방에 넣을 수 있는 보석이라면
        while (index < N && jewels[index].first <= bags[i]) {
            j.push({jewels[index].second, jewels[index].first});
            index++;
        }

        if (!j.empty()) {
            cost += j.top().first;
            j.pop();
        }
    }

    std::cout << cost;
    return 0;
}