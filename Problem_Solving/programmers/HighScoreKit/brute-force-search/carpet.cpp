#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 사각형 전체 크기
    int area = brown + yellow;
    
    // 갈색 격자 수가 최소 8로 x, y는 3이 최소값이다.
    int y = 3;
    
    while (y < yellow + 3)
    {
        if (!(area % y) && (y - 2) * (area / y - 2) == yellow)
            break;
        y++;
    }
    
    return {area / y, y};
}