#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long N;
    std::cin >> N;
    std::map<long long, long long> cards;

    // Key를 Ascending order 정렬
    for (long long i = 0; i < N; i++)
    {
        long long t;
        std::cin >> t;
        cards[t]++;
    }

    long long max = 0;
    long long index = 0;
    for (auto& i : cards)
    {
        if (i.second > max) {
            max = i.second;
            index = i.first;
        }
    }

    std::cout << index;
    return 0;
}