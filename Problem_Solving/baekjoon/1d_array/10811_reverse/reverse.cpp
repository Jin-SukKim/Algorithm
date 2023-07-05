#include <iostream>
#include <vector>
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> v(N, 1);
    for (int i = 1; i < N; i++)
    {
        v[i] = v[i-1] + 1;
    }

    while (M--)
    {
        int i, j;
        std::cin >> i >> j;
        // 일정 구간이 역순으로 바뀌도록 해준다.
        for (--i, --j; i <= j; i++, j--)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    for (int& i : v)
        std::cout << i << " ";
    return 0;
}