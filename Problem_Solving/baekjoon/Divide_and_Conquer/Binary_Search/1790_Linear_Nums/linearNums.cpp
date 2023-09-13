#include <algorithm>
#include <iostream>
#include <string>

int calLength(int N)
{
    // 1 ~ 9 : 9 * 1;
    // 10 ~ 99 : 90 * 2
    // 100 ~ 999 : 900 * 3 etc
    long long len = 0;
    for (int start = 1, i = 1; start <= N; start *= 10, i++)
    {
        int end = start * 10 - 1;
        if (end > N)
        {
            end = N;
        }
        len += (long long)(end - start + 1) * i;
    }
    return len;
}

int binary_search(int l, int r, long long target)
{
    if (l >= r)
        return r;

    int mid = l + (r - l) / 2;
    long long len = calLength(mid);

    if (len < target)
        return binary_search(mid + 1, r, target);
    else
        return binary_search(l, mid, target);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    long long K;

    std::cin >> N >> K;
    if (calLength(N) < K)
    {
        std::cout << -1;
        return 0;
    }
    
    // k번째 숫자 구하기
    int num = binary_search(1, N, K);
    // K번째 숫자가 들어있는 숫자 모두를 더하면 나오는 길이
    // ex) 숫자 16이면 K가 1이나 6을 가르켜도 16 까지의 길이를 구한다.
    int num_len = calLength(num);

    std::string s_num = std::to_string(num);

    // s_num의 뒤에서 (num - K)만큼 앞에 있는 숫자 구하기
    std::cout << s_num[(s_num.size() - 1) - (num_len - K)];


    return 0;
}