#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	// n의 최대값이 500이기에 Factorial을 구하는 것은 무리이다.(int범위도 벗어나며 시간초과도 날것이다)
	/*
		뒤에 0이 나오는 경우는 10이 곱해진 경우이다.
		10 = 2 * 5인 2와 5의 최소공배수인데 결국 N!을 소인수분해 했을 때 나오는
		2와 5의 개수를 세서 더 적은 것을 구하면 된다.

		기본적으로 2의 개수가 더 많으므로 5의 개수를 세면 된다.
		주의할 점은 5의 제곱수인데 25 = 5 * 5로 0을 2개 만들 수 있고
		125는 3개 만들 수 있다.
	*/
	int count = 0;
	for (int i = 5; i <= n; i *= 5)
		count += n / i;

	std::cout << count;
	return 0;
}