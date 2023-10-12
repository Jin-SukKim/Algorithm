#include <cmath>
#include <iostream>
using namespace std;

long long calPrice(int price, int count, long long sum) {
    if (!count) {
        return sum;
    }

    return calPrice(price, count - 1, sum + price * count);
}

long long solution(int price, int money, int count)
{
    long long answer = -1;

    answer = calPrice(price, count, 0);
    
    if (answer > money)
        return answer - money;
    return 0;
}