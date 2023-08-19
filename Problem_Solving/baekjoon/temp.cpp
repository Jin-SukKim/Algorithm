#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<int> &coins, int &N, int &count, int depth) {
    if (depth == N) {
        // col의 코인을 뒤집기
        int total = 0;
        int bit = 1;
        // 각 열을 뒤집을 지는 tail 개수가 최소가 되도록 결정한다.
        for (int i = 0; i < N; i++) {
            int tail = 0;
            for (int j = 0; j < N; j++) {
                // 열의 tail의 개수
                if (coins[j] & bit)
                    tail++;
            }
            bit <<= 1;
            // tail의 개수를 뒤집으면 tail의 개수는 head의 개수로 바뀐다.
            // N에 tail의 개수를 빼면 현재 있는 head의 개수가 된다.
            // 둘 중 작은 값을 사용하면 열을 뒤집을지 안뒤집을지 알 수 있다.
            total += tail < N - tail ? tail : N - tail;
        }
        // 가장 작은 tail의 개수를 원한다.
        // 현재 case의 head의 개수와 여태까지의 tail의 개수를 샌다.
        count = count < total ? count : total;
        return;
    }

    // row의 코인을 모두 뒤집는다
    coins[depth] = ~coins[depth];
    dfs(coins, N, count, depth + 1);
    // 원래대로 복구
    coins[depth] = ~coins[depth];
    dfs(coins, N, count, depth + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    // 최대 20 이하의 자연수인데 'T'와 'H'을 bit로 표현하므로 최대 20bit가
    // 필요하다.
    std::vector<int> coins(N);

    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        int bit = 1;
        for (int j = 0; j < N; j++) {
            // Tail은 bit의 1로 Head는 0으로 표현
            // 1만 표시하면 되기에 Tail만 계속 추적한다.
            if (s[j] == 'T')
                coins[i] |= bit;
            bit <<= 1;
        }
    }

    // 20 x 20 = 400으로 최대 400까지 카운트할 수 있으면 된다.
    int count = 1000;
    dfs(coins, N, count, 0);
    std::cout << count;

    return 0;
}