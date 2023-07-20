#include <iostream>
#include <vector>

std::vector<int> getPrime(int m)
{
	std::vector<int> prime(m + 1);

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

	return prime;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(NULL);

	std::vector<int> prime;
	prime = getPrime(1000000);
	
	while (1)
	{
		int n;
		std::cin >> n;

		if (n == 0)
			break;
			
		bool guess = false;
		for (int i = 3; i < n; i += 2)
		{
			if (prime[i] == 0 && prime[n - i] == 0)
			{
				std::cout << n << " = " << i << " + " << n - i << "\n";
				guess = true;
				break;
			}
		}

		if (!guess)
			std::cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}