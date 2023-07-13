#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	int n;
	std::cin >> n;

	std::vector<int> x(n);
	std::vector<int> y(n);

	for (int i = 0; i < n; i++)
		std::cin >> x[i] >> y[i];

	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());

	std::cout << (x[n - 1] - x[0]) * (y[n - 1] - y[0]);

	return 0;
}