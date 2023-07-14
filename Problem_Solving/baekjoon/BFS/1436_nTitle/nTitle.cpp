#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int title = 666, count = 0;
	int n;
	std::cin >> n;
	while (1)
	{
		int num = title;

		while (num)
		{	
			// 제목에 666이 있는지 확인
			if (num % 1000 == 666)
			{
				count++;
				break;
			}
			num /= 10;
		}

		// n번째 타이틀을 찾으면 출력
		if (count == n)
		{
			std::cout << title;
			break;
		}
		title++;
	}
	return 0;
}