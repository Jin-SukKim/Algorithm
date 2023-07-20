#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	/*
		유클리드 호제법(Euclidean Algorithm)
		두 수,a,b 중 큰 수를 작은 수로 나눠 나온 나머지로
		다시 나눈 값을 나눈 뒤 나머지를 구하는 과정을 반복해 나머지가 0이 되었을 때
		나머지가 0이 나오게 한 나누는 값이 최대공약수가 된다.
		GreatestCommonDivisor(GCD)
	*/
	int GCD = n < m ? m : n;
	int divisor = n < m ? n : m;
	while (divisor)
	{
		int remain = GCD % divisor;
		GCD = divisor;
		divisor = remain;
	}

	// 최소공배수(Leat Common Multiple)은 두 자연수의 곲 / 최대공약수이다.
	int LCM = n * m / GCD;

	std::cout << GCD << '\n' << LCM;
	return 0;
}