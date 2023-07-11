#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	int N;
    std::cin >> N;
 
    if (N == 1) return 0;
 
    for (int i = 2; i <= N; i++) {
        // 더 이상 나눌 수 없을 때 까지 나눠준다.
        while (N % i == 0) {
            std::cout << i << "\n";
            N /= i;
        }
    }
	return 0;
}