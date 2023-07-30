#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int E, S, M;
	std::cin >> E >> S >> M;

	int year = 1;
	while (1)
	{
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
			break;
		year++;
	}

	std::cout << year;
	return 0;
}
