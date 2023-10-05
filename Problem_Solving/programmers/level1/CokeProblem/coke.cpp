#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (1)
    {
        int remain = n % a;
        int get = n / a * b;
        if (get == 0)
            break;
        answer += get;
        n = get + remain;
    }
    return answer;
}