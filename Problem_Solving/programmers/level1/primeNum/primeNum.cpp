#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int primeNum(int& n)
{
    set<int> prime;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) {
            prime.insert(i);
            prime.insert(n / i);
        }
    }
    
    return prime.size();
}

int solution(int left, int right) {
    int answer = 0;
    
    for (; left <= right; left++)
    {
        if (primeNum(left) & 1) 
            answer -= left;
        else
            answer += left;
    }
    
    return answer;
}