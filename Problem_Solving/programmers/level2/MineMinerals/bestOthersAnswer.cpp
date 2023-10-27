#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// 각 광물마다 소모하는 각 곡괭이의 피로도
unordered_map<string, int> dic[3] = {
    { { "diamond", 1 }, { "iron", 1 }, { "stone", 1 } },    // 다이아몬드 곡괭이
    { { "diamond", 5 }, { "iron", 1 }, { "stone", 1 } },    // 철 곡괭이
    { { "diamond", 25 }, { "iron", 5 }, { "stone", 1 } }    // 돌 곡괭이
};

int solution(vector<int> picks, vector<string> minerals) {
    // tool의 재료에 따른 5개의 광물을 캘 때 소모하는 피로도 
    auto calc = [&](int idx, int tool) -> int {
        int ret = 0;
        for (int i = 0; i < 5 && idx + i < minerals.size(); ++i) ret += dic[tool][minerals[idx + i]];

        return ret;
    };

    // recursive 방식
    auto go = [&](auto& self, int a, int b, int c, int idx = 0) -> int {
        if (a + b + c == 0 || idx >= minerals.size()) return 0;

        int ret = 0x3f3f3f3f;
        // 남은 곡괭이로 5개의 광물을 캔 것 중 가장 피로도가 적은 걸 찾기
        // 남은 재질의 곡괭이 모두 계산해본다.
        if (a) ret = min(ret, calc(idx, 0) + self(self, a - 1, b, c, idx + 5));
        if (b) ret = min(ret, calc(idx, 1) + self(self, a, b - 1, c, idx + 5));
        if (c) ret = min(ret, calc(idx, 2) + self(self, a, b, c - 1, idx + 5));

        return ret;
    };

    return go(go, picks[0], picks[1], picks[2]);
}
