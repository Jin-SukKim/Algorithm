#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 총 인원 수
    vector<int> student(n, 1);
    // 잃어버린 학생
    for (int& i : lost)
        student[i - 1]--;
    // 여분을 가진 학생
    for (int& i : reserve) 
        student[i - 1]++;
    
    for (int i = 0; i < n; i++)
    {
        if (!student[i]) {
            // 여분이 있다면
            if (i && student[i - 1] == 2)
            {
                student[i - 1]--;
                student[i]++;
            }
            else if (i < n - 1 && student[i + 1] == 2)
            {
                student[i + 1]--;
                student[i]++;
            }
        }
    }
    
    // 체육복을 가진 학생이 몇인지 확인
    for (int& i : student)
        if (i)
            answer++;
    
    return answer;
}