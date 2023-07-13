#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	int n;
	std::cin >> n;

	// 각 좌표의 x와 y 값을 받는다.
	std::vector<int> x(n);
	std::vector<int> y(n);

	for (int i = 0; i < n; i++)
		std::cin >> x[i] >> y[i];

	// 정렬
	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());

	// 가장 큰 값에서 가장 작은 좌표 값을 빼면 한 변의 한 변의 길이가 나와 곱해 넓이를 구한다.
	std::cout << (x[n - 1] - x[0]) * (y[n - 1] - y[0]);

	return 0;
}