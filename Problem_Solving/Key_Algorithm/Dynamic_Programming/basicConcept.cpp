#include <iostream>
#include <vector>
/*
    다이나믹 프로그래밍(DP)

    1. 큰 문제를 여러 개의 작은 문제로 나누어 푸는 기법
    2. 문제를 작은 문제의 정답들을 통해 구할 수 있다.
*/

// Tabulation, Bottom-Up(상향식) - 반복문
// 작은 문제부터 살펴본 후 작은 문제의 정답을 이용해 큰 문제의 정답을 찾는다.
int fibonacci(int n)
{
    // 피보나치의 작은 문제인 0, 1, 2의 값들을 저장해두면
    // 3을 구하는 과정에서 이전에 구한 값들을 이용해 문제를 풀 수 있다.
    // ex) 3 = 2 + 1, 4 = 3 + 2 = 2 + 1 + 1 + 1 = 1 + 1 + 1 + 1 + 0 + 1 + 0
    // 과 같이 기존 피보나치는 각각 1과 0까지 구한 뒤 더해준다면 DP는 미리 계산해둔 값을 저장해
    // 맨 끝인 1과 0까지 갈 필요가 없어진다.
    std::vector<int> fib(n+1, 0);
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// Memoization, Top-Down(하향식) - 재귀
// 작은 문제들을 해결했는지 확인해가며 풀어준다.
std::vector<int> save(100);
int fibonacci2(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    if (save[n])
        return save[n];
    
    save[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
    return save[n];

}
int main()
{

}