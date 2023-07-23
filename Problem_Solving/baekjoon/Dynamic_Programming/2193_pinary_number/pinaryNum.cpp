#include <iostream>
#include <vector>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	if (n == 1 || n == 2)
	{
		std::cout << 1;
		return 0;
	}
	// 0으로 시작하지 않는다.
	// 1이 두 번 연속 나타나지 않는다.
	std::vector<long long> binary(n + 1);
	binary[1] = binary[2] = 1;

	// 규칙을 보면 피보나치와 같다.
	for (int i = 3; i <= n; i++)
		binary[i] = binary[i - 1] + binary[i - 2];

	std::cout << binary[n];

	return 0;
}