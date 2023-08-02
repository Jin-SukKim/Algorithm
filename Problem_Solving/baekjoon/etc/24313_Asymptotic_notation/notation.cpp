#include <iostream>
/*
	O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인
	양의 상수 c와 n0가 존재한다}
	함수 f(n) = a1n + a0, 양의 정수 c, n0가 주어질 경우 O(n) 정의를 만족하는지 알아보자.
*/
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int a1, a0, c, n0;
	std::cin >> a1 >> a0 >> c >> n0;
	// 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다
	// f(n) <= c * g(n) && f(n) >= n0
	// 1. c - a1이 양수(음수이면 양수인 a0보다 클 수 없다)
	// a0이 음수일 때 n의 값이 커질때 부등식이 만족하지 않을 수 있으므로 예외처리를 해줘야한다.
	// 즉, a1의 값이 c보다 작거나 같아야된다.
	// 2. n0을 대입했을 때 부등식이 true일 때
	if ((a1 * n0 + a0) <= (c * n0) && c >= a1)
		std::cout << 1;
	else
		std::cout << 0;
	return 0;
}