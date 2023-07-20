#include <iostream>
#include <cmath>
#include <stack>
// A진법을 B진법으로 변환
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int a, b;
	std::cin >> a >> b;

	int length;
	std::cin >> length;

	// A진법을 10진법으로 변환
	int base10 = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		int n;
		std::cin >> n;

		// 진법은 한 자리수가 올라갈 수록 base에 i만큼 제곱을 해준다.
		base10 += n * std::pow(a, i);
	}

	std::stack<int> baseB;
	// 10진법을 B진법으로 변환
	while (base10)
	{
		baseB.push(base10 % b);
		base10 /= b;
	}

	while (!baseB.empty())
	{
		std::cout << baseB.top() << " ";
		baseB.pop();
	}
	return 0;
}