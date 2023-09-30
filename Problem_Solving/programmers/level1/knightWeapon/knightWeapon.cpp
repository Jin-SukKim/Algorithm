#include <string>
#include <vector>

using namespace std;

int divisor(int n)
{
    if (n == 1)
        return 1;
    
    int count = 0;
    for (int i = 1; i * i <= n; i++){
        if (i * i == n)
            count++;
        else if (n % i == 0)
            count += 2;
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
    {
        int w = divisor(i);
        if (limit < w)
            w = power;
        answer += w;
    }
    
    return answer;
}