#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n, vector<int>(n));
    int num = 1, dir = 0, row = -1, col = 0;
    // 결국 소용돌이 처럼 3 방향의 반복
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i % 3 == 0) // 아래방향
                triangle[++row][col] = num++;
            else if (i % 3 == 1) // 오른쪽 방향
                triangle[row][++col] = num++;
            else if (i % 3 == 2) // 왼쪽 대각선 위
                triangle[--row][--col] = num++;
        }
    }
    
    // 답 입력
    for (auto& v : triangle)
        for (int& i : v)
            if (i)
                answer.push_back(i);
    
    return answer;
}