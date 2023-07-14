#include <iostream>

int sum(int n)
{
	int s = 0;
	while (n)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;

	int count = 0;
	for (int i = n; i > 0; i /= 10)
		count++;

	// 각 자리의 수가 가질 수 있는 최대 숫자는 9이므로 숫자의 길이 * 9를 빼주면
	// 최소 생성자가 된다.
	for (int i = n - count * 9; i <= n; i++)
	{
		if (i + sum(i) == n)
		{
			std::cout << i;
			return 0;
		}
	}
	std::cout << 0;

	return 0;
}