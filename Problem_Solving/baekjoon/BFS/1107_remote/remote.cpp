#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// 고장난 버튼을 누르면 0, 아니면 length
int possible(std::vector<bool>& remote, int n)
{
	// 채널이 0인 경우
	if (n == 0)
		return remote[0] ? 0 : 1;

	int len = 0;
	while (n > 0)
	{
		// 고장난 버튼이면
		if (remote[n % 10]) return 0;
		len += 1;
		n /= 10;
	}
	return len;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	if (n == 100)
	{
		std::cout << 0;
		return 0;
	}

	std::vector<bool> remote(10, false);
	for (int i = 0; i < m; i++)
	{
		int j;
		std::cin >> j;
		remote[j] = true;
	}

	// +나 -만 눌러서 이동하는 경우
	int count = std::abs(n - 100);

	for (int i = 0; i <= 1000000; i++)
	{
		int c = i;
		int len = possible(remote, i);

		// 고장난 버튼을 제외하고 누를 수 있는 채널로 이동한 경우
		if (len > 0)
		{
			// 누른 번호로 이동한 채널에서 목표 채널까지 +나 -를 누르는 횟수
			int press = std::abs(c - n);
			count = std::min(count, len + press);
		}
	}

	std::cout << count;
	return 0;
}
