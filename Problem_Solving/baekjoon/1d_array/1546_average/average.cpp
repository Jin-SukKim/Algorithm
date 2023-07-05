#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(false);
    float N;
    std::cin >> N;
    std::vector<float> v(N);
    
    for (int i = 0; i < N; i++)
    {
        float score;
        std::cin >> score;
        v[i] = score;
    }

    // 점수 중 최댓값을 골라 모든 점수를 최대값으로 나눈 뒤 100을 곱해준다.
    float highest = *std::max_element(v.begin(), v.end());
    float average = 0;
    for (float& i : v)
    {
        average += i / highest * 100;
    }
    
    // 고친 점수들의 평균을 구한다.
    std::cout << average / N;
    return 0;
}