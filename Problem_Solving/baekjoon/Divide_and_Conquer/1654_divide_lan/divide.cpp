#include <algorithm>
#include <iostream>
#include <vector>

// 랜선을 length로 자를 때 나오는 개수
unsigned int cal(std::vector<unsigned int> &lan, unsigned int length) {
    unsigned int count = 0;
    for (unsigned int &i : lan)
        count += i / length;
    return count;
}

void search(std::vector<unsigned int> &lan, unsigned int l, unsigned int r, unsigned int &target, unsigned int &ans) {
    if (l > r)
        return;

    unsigned int mid = l + (r - l) / 2;
    unsigned int count = cal(lan, mid);

    if (count < target)
        search(lan, l, mid - 1, target, ans);
    else {
        // 현재 mid로 나눈 값이 N보다 크거나 같다면
        // 길이가 더 긴 경우는 가능한지 검사한다.
        ans = std::max(mid, ans);
        search(lan, mid + 1, r, target, ans);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned int K, N;
    std::cin >> K >> N;

    unsigned int max = 0;
    std::vector<unsigned int> lan(K);
    for (unsigned int i = 0; i < K; i++) {
        std::cin >> lan[i];
        if (max < lan[i])
            max = lan[i];
    }

    unsigned int ans = 0;
    search(lan, 1, max, N, ans);
    std::cout << ans;
    return 0;
}