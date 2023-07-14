#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int N, M;
	std::cin >> N >> M;
	std::vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		int c;
		std::cin >> c;
		v[i] = c;
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int h = j + 1; h < N; h++)
			{
				int check = v[i] + v[j] + v[h];
				if (check > M)
					continue;;
					
				if (sum < check)
					sum = check;
				
			}
		}
	}

	std::cout << sum;

	return 0;
}