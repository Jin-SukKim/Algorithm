#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;

	std::vector<int> prime(m+1);
	// 0과 1은 소수가 아니다.
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i <= m; i++)
	{
		// 2부터 처음 나온 수는 소수이다.
		if (prime[i] == 0)
		{
			// 소수의 배수는 소수가 아니다 (ex: 2 * 2 = 4, 6, 그리고 3 * 3 = 9등)
			for (int j = i * i; j <= m; j += i)
			{
				prime[j] = 1;
			}
		}
	}

	for (; n <= m; n++)
		if (prime[n] == 0) std::cout << n << '\n';

	return 0;
}