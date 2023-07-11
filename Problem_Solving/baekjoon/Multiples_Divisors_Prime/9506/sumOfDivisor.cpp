#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while (1)
	{
		int N;
		std::cin >> N;

		if (N == -1)
		{
			break;
		}

		std::cout << N;

		std::vector<int> v;
		int sum = 0;
		
		for (int i = 1; i <= N / 2; i++)
		{
			if (N % i == 0)
			{
				v.push_back(i);

				sum += i;
			}
		}

		if (sum == N)
		{
			std::cout << " = ";

			for (int i = 0; i < v.size() - 1; i++)
			{
				std::cout << v[i] << " + ";
			}

			std::cout << v[v.size() - 1] << "\n";

			continue;
		}

		std::cout << " is NOT perfect.\n";
	}

	return 0;
}