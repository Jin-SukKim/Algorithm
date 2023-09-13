#include <algorithm>
#include <iostream>
#include <vector>

long long cutting(std::vector<long long>& heights, long long h)
{
    long long total = 0;
    for (long long& i : heights)
    {
        if (i - h > 0)
            total += i - h;
    }
    return total;
}

void search(std::vector<long long>& heights, long long l, long long r, long long& target, long long& ans)
{
    if (l > r)
        return;

    long long mid = l + (r - l) / 2;
    long long cut = cutting(heights, mid);
    if (cut < target)
        search(heights, l, mid - 1, target, ans);
    else {
        ans = std::max(mid, ans);
        search(heights, mid + 1, r, target, ans);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long N, M;

    std::cin >> N >> M;

    long long maxHeight = 0;
    std::vector<long long> heights(N);
    for (long long i = 0; i < N; i++) {
        std::cin >> heights[i];
        if (maxHeight < heights[i])
            maxHeight = heights[i];
    }

    long long ans = 0;
    search(heights, 0, maxHeight, M, ans);
    std::cout << ans;

    return 0;
}