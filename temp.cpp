#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
// 최대 공약수
int GCD(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

// 최소 공배수
int LCM(int a, int b)
{
    return (a * b)/ GCD(a, b);
}

long long Factorial(vector<long long>& fac, const int& n)
{
    for (int i = fac.size(); i < n + 1; i++)
        fac.push_back(fac[i - 1] * i);
    return fac[n];
}

// 조합 개수
// nCr = nPr / r! = n! / ((n-r)! * r!)
int Combination(vector<long long>& fac, const int& n) {
    if (n == 2)
        return 1;
    return Factorial(fac, n) / (Factorial(fac, n - 2) * 2);
}

bool check(const int& a, const int& b)
{
    if (1 < (a / b) && (a / b) < 5)
        return true;
    
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m;
    vector<long long> fac(1, 1);
    
    for (int& w : weights)
        m[w]++;

    for (auto [w1, p1] : m)
    {
        if (p1 > 1)
            // 같은 몸무게인 사람이 여러명일 때
            answer += Combination(fac, p1);
        
        for (auto [w2, p2] : m)
        {
            if (p2 > 0 && w1 != w2) {
                int lcm = LCM(w1, w2);
                
                // 만약 최소 공배수가 조합 중의 한값과 같다면 
                // 두 값은 균형을 이루지만 조건을 확인하는 조건식에 맞지않아 2를 곱한다.
                if (lcm == w2)
                    lcm *= 2;
                
                if (check(lcm, w1) && check(lcm, w2)) {
                    cout << w1 << ' ' << w2 << '\n';
                    answer += p1 * p2;
                }
            }
        }

        m[w1] = 0;
    }
    
    return answer;
}

int main()
{
    solution({100, 180, 360, 100, 270});
    return 0;
}