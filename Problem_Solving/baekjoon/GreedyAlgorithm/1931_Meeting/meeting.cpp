#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    
    // 각 회의의 끝과 시작 시간을 저장
    std::vector<std::pair<int, int>> m(N);
    for (int i = 0; i < N; i++)
    {
        int start, end;
        std::cin >> start >> end;
        m[i] = {end, start};
    }

    // 끝나는 시간 순으로 정렬
    // 빨리 끝나야 여러 회의를 할 수 있다.
    std::sort(m.begin(), m.end());

    int count = 0;
    int lastMeeting = 0;
    for (int i = 0; i < N; i++)
    {
        // 이전 미팅의 끝나는 시간보다 시작 시간이 빠르다면
        // 회의에 참석하지 못하므로 통과
        if (lastMeeting > m[i].second)
            continue;
        // 가장 빨리 끝나는 미팅
        lastMeeting = m[i].first;
        count++;
    }

    std::cout << count;


    return 0;
}