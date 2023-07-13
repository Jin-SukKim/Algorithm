#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::vector<int> t(3);
	std::cin >> t[0] >> t[1] >> t[2];
	std::sort(t.begin(), t.end());
	// 삼각형을 만들기 위하 필요한 변의 길이
	// c < a + b 가장 긴 변의 길이가 두 변의 합보다 작아야된다.
	if (t[2] < (t[0] + t[1]))
		std::cout << t[0] + t[1] + t[2];
	// 아닌 경우 가장 긴 변의 길이를 줄여준다 a + b - 1
	else
		std::cout << (t[0] + t[1]) * 2 - 1;
	return 0;
}