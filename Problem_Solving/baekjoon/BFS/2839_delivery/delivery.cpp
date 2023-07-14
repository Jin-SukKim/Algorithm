#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int kg;
	std::cin >> kg;

	int count = 0;
	while (kg >= 0)
	{
		// 5kg을 우선적으로 사용한다.
		// 5로 나누어 떨어지거나 kg이 0이 되면 출력된다.
		if (kg % 5 == 0)
		{
			count += kg / 5;
			std::cout << count;
			return 0;
		}

		// 5로 나누어지지 않는다면 3을 빼 최소한의 3을 사용하도록 한다.
		// 0으로 나누어 떨어지지 않는다면 -1을 출력해준다.
		kg -= 3;
		count++;
	}
	
	std::cout << -1;
	return 0;
}