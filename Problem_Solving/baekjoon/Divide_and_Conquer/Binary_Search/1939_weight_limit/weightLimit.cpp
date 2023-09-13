#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#include <array>

class Answer {
  public:
    int max = 0;
    int min = INT_MAX;
    Answer() {
        std::cin >> N >> M;

        b.resize(N + 1);
        for (int i = 0; i < M; i++) {
            int A, B, C;
            std::cin >> A >> B >> C;
            // 양방향 그래프
            b[A].push_back({B, C});
            b[B].push_back({A, C});

            if (max < C)
                max = C;
            if (min > C)
                min = C;
        }

        std::cin >> from >> to;
    }

    // 현재 설정한 무게보다 더 큰 무게로 넘어갈 수 있는지 확인
    bool bfsSearch(int curW) {
        // 다리의 한계 무게가 무거운 순서대로 나열
        std::priority_queue<std::pair<int, int>> q;
        std::array<bool, 100001> visited{false};
        q.push({curW, from});
        visited[from] = true;

        while (!q.empty()) {
            auto [w, cur] = q.top();
            q.pop();

            if (cur == to)
                return true;

            for (auto &[next, weight] : b[cur]) {
                // 이전에 방문했던가 현재 무게보다 작은 무게면 넘어간다.
                if (weight < curW || visited[next])
                    continue;

                visited[next] = true;
                q.push({weight, next});
            }
        }

        return false;
    }

    void binary_search(int l, int r) {
        while (l <= r) {
            // 중간 무게
            int mid = l + (r - l) / 2;
            // 지금 무게로 문제없이 도착섬까지 도착할 수 있다면
            if (bfsSearch(mid))
                // 더 무거운 무게는 가능한지 확인
                l = mid + 1;
            else
                r = mid - 1;
        }
        std::cout << r;
    }

  private:
    std::vector<std::vector<std::pair<int, int>>> b;
    int N, M, from, to;
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Answer A;
    A.binary_search(A.min, A.max);

    return 0;
}