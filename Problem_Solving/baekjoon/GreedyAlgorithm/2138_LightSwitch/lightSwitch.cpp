#include <iostream>
#include <string>
#include <vector>

// version 0은 index 0, 1 전구를 키지 않고 시작하는 케이스
// version 1은 0, 1 전구를 키고 시작하는 케이스다.
int switchCase(std::vector<bool> lights, std::vector<bool> &result, int &N,
               int version) {
    int count = 0;

    if (version) {
        lights[0] = !lights[0];
        lights[1] = !lights[1];
        count++;
    }

    for (int i = 1; i < N; i++) {
        if (lights[i - 1] != result[i - 1]) {
            if (i == N - 1) {
                lights[N - 2] = !lights[N - 2];
                lights[N - 1] = !lights[N - 1];
            } else {
                for (int k = i - 1; k < i + 2; k++)
                    lights[k] = !lights[k];
            }
            count++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (lights[i] != result[i])
            return -1;
    }

    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<bool> lights(N);
    std::vector<bool> result(N);

    std::string s;
    std::cin >> s;
    for (int i = 0; i < N; i++)
        lights[i] = s[i] - '0';

    std::cin >> s;
    for (int i = 0; i < N; i++)
        result[i] = s[i] - '0';

    int count = switchCase(lights, result, N, 0);
    int count2 = switchCase(lights, result, N, 1);

    if (count < 0 && count2 < 0)
        std::cout << -1;
    else if (count < 0)
        std::cout << count2;
    else if (count2 < 0)
        std::cout << count;
    else {
        count = count < count2 ? count : count2;
        std::cout << count;
    }

    return 0;
}