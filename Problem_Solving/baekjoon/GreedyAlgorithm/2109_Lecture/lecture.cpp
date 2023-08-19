#include <algorithm>
#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> lecture(n);
    for (int i = 0; i < n; i++)
        std::cin >> lecture[i].second >> lecture[i].first;

    // 날짜 순으로 정렬
    std::sort(lecture.begin(), lecture.end());

    // 강의의 비용을 넣으면 가장 작은 수가 root가 되는 min heap이다.
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int fee = 0;
    int day = lecture[0].first;
    for (int i = 0; i < n; i++)
    {
        // 비용을 넣는다.
        q.push(lecture[i].second);
        // day1에는 q에 1값만 들어있어야 되므로 q의 size가 더 크면
        // 맨 위의 값을 빼주는데 min heap이라 맨 위의 값은 i day중
        // 더 작은 비용의 강의가 된다.
        if (q.size() > lecture[i].first)
            q.pop();
    }

    while (!q.empty())
    {
        fee += q.top();
        q.pop();
    }
    std::cout << fee;

    return 0;
}