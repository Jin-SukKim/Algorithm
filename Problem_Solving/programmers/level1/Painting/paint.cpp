#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int paint = 0;
    int count = 0;
    for (int& s : section)
    {
        if (s > paint)
        {
            count++;
            paint = s + m - 1; // 페인트칠한 마지막 위치
        }
    }
    
    return count;
}