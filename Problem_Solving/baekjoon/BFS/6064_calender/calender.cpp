#include <iostream>

// 곱셉의 역원을 구하는 유클리드 호제법
// a와 b 사이의 최대공약수를 구하는 법
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최대공배수 구하는 공식
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int m, n, x, y;
        std::cin >> m >> n >> x >> y;
        int end = lcm(m, n); // 종말의 마지막 해

        int year = -1;
        // x값을 기준으로 m을 더해 루프를 돌린다.
        for (int i = x; i <= end; i += m) 
        {
            // y값을 찾는다.
            int ny = i % n ? i % n : n;
            
            // y값을 찾았다면
            if(ny == y){
                year = i;
                break;
            }
        }
        std::cout << year << '\n';
    }

    return 0;
}