#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum = 0;
    long long q1 = 0, q2 = 0;
    for (int i = 0; i < queue1.size(); i++) {
        q1 += queue1[i];
        q2 += queue2[i];
    }
    sum += q1 + q2;
    
    // sum이 홀수면 두 큐의 원소 합을 같게 만들 수 없다.
    if (sum & 1)
        return -1;
    sum /= 2;
    
    int i = 0, j = 0;
    while (q1 != q2)
    {
        if (q1 > q2)
        {
            if (i < queue1.size())
            {
                q1 -= queue1[i];
                q2 += queue1[i];
            }
            // i가 queue의 size를 넘으면 그 뒤의 추가된 숫자를 비교하는 것
            else if (i < queue1.size() + queue2.size())
            {
                q1 -= queue2[i - queue1.size()];
                q2 += queue2[i - queue1.size()];
            }
            // 큐의 원소가 바뀌다 결국 전부 다 바뀌면 처음과 같은 상황이므로
            // 각 큐의 원소 합을 같게 만들 수 없는 경우다.
            else
                return -1;
            
            i++;
        } else {
            if (j < queue2.size())
            {
                q2 -= queue2[j];
                q1 += queue2[j];
            } else if (j < queue2.size() + queue1.size())
            {
                q2 -= queue1[j - queue2.size()];
                q1 += queue1[j - queue2.size()];
            }
            else
                return -1;
                
            j++;
        }
        answer++;
    }
    
    return answer;
}