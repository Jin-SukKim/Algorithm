#include <string>
#include <vector>
using namespace std;


// double pointer를 활용
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, (int)sequence.size()};
    
    int left = 0, right = 0;
    int sum = 0;
    while (left <= right && right <= sequence.size())
    {   
        // sum이 목표한 값과 같을 때
        if (sum == k) {
            // 더 짧은 길이의 범위를 가진 답을 저장
            if (right - 1 - left < answer[1] - answer[0]) {
                answer[0] = left;
                answer[1] = right - 1;
            }   
            sum -= sequence[left++];
        }
        // sum의 값이 더 크나면 왼쪽 포인터를 이동
        else if (sum > k)
            sum -= sequence[left++];
        // sum의 값이 작다면 오른쪽 포인터를 이동
        else if (sum < k)
            sum += sequence[right++];
    }
    
    return answer;
}