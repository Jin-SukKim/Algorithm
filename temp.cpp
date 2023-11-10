#include <string>
#include <vector>
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
    
    bool A = false;
    int i = 0;
    
    for (; i < arrayA.size(); i++)
    {
        if (arrayA[i] % gcdB == 0) 
            break;
        
        if (arrayB[i] % gcdA == 0) {
            A = true;
            break;
        }
    }
    
    vector<int>& array = arrayB;
    int gcd = gcdA;
    if (A) {
        array = arrayA;
        gcd = gcdB;
    }
    
    for (; i < array.size(); i++)
    {
        if (array[i] % gcd == 0)
            return 0;
    }
    
    return gcd;
}
int main()
{
    solution({10, 20}, {5, 17});
    return 0;
}