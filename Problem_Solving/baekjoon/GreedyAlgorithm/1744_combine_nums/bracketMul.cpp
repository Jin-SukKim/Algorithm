#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    // 양수 * 양수
    std::vector<int> pos;
    // 음수와 음수를 곱하면 양수가 되므로 가장 작은 음수들끼리 곱해준다.
    std::vector<int> neg;

    int result = 0;
    bool isZero = false;
    for (int i = 0; i < N; i++) {
        int n;
        std::cin >> n;
        // 0은 음수가 홀수인 경우 가장 큰 음수에 0을 곱해 0으로 만들어준다.
        if (n == 0)
            isZero = true;
        // 1은 곱해주면 값에 변화가 없으므로 그냥 더해준다.
        else if (n == 1)
            result++;
        else if (n > 1)
            pos.push_back(n);
        else
            neg.push_back(n);
    }
    
    // 가장 큰 수가 맨 앞으로 오도록 정렬
    std::sort(pos.begin(), pos.end(), std::greater<int>());
    // 가장 작은 수가 맨 앞으로 오도록 정렬
    std::sort(neg.begin(), neg.end());

    // 양수가 홀수개라면 제일 작은 수는 그냥 더해준다.
    if (pos.size() & 1)
    {
        result += pos.back();
        pos.pop_back();
    }

    // 음수 배열이 홀수라면 0으로 가장 큰 수를 곱해 0으로 만들어준다.
    // 맨 마지막 bit이 1이면 홀수 0이면 짝수다.
    if (neg.size() & 1) {
        // 0이 없다면 그냥 더해줘야한다.
        if (!isZero)
            result += neg.back();
        neg.pop_back();
    }

    for (int i = 0; i < pos.size(); i += 2)
        result += pos[i] * pos[i + 1]; 
        
    for (int i = 0; i < neg.size(); i += 2)
        result += neg[i] * neg[i + 1];

    std::cout << result;

    return 0;
}