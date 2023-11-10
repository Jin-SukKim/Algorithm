#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 최대공약수
int GCD(int a, int b) {
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}

// 모든 벡터의 원소들의 최대공약수
int GetArrayGCD(const vector<int>& a)
{
    int gcd = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        gcd = GCD(gcd, a[i]);
    }
    return gcd;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = GetArrayGCD(arrayA);
    int gcdB = GetArrayGCD(arrayB);
    
    for (int& i : arrayA) {
        if (i % gcdB == 0) {
            gcdB = 0;
            break;
        }      
    }
    
    for (int& i : arrayB) {
        if (i % gcdA == 0) {
            gcdA = 0;
            break;
        }      
    }
    
    return max(gcdA, gcdB);
}