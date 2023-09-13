#include <algorithm>
#include <iostream>
#include <vector>

void search_max(std::vector<int>& line, int l, int r, int& C, int& res)
{
    if (l > r)
        return;

    int mid = l + (r - l) / 2;
    int count = 1; // 첫 공유기는 맨 첫 위치에 설치
    int start = line.front();

    for (int i = 1; i < line.size(); i++)
    {
        int end = line[i];
        if (end - start >= mid)
        {
            count++;
            start = end;
        }
    }

    if (count < C)
    {
        return search_max(line, l, mid - 1, C, res);
    }
    else
    {
        res = mid;
        return search_max(line, mid + 1, r, C, res);
    }   
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    std::vector<int> line(N);
    for (int i = 0; i < N; i++)
        std::cin >> line[i];

    std::sort(line.begin(), line.end());
    int res = 0;
    search_max(line, 0, line[N - 1], C, res);
    std::cout << res;


    return 0;
}