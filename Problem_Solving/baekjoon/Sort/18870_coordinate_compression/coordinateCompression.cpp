#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

/*
	좌표 압축 알고리즘 : 모든 구간이 아니라, 중요한 구간이나, 숫자만 들고있는 기법.
	순위가 중요한 알고리즘에서 입력값의 개수 < 입력값의 범위일 때 사용한다.

	즉, 수의 값과 상관 없이 숫자 간의 대소관계만 알면 될 때 이용하는 알고리즘이다.
*/
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> map(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		map[i] = x;
	}

	// 압축좌표
	std::vector<int> compress = map;
	std::sort(compress.begin(), compress.end());
	// unique는 중복된 값을 삭제하지만 vecotr의 길이는 유지되 메모리가 낭비된다.
	// unique는 새로운 end()를 return하면 erase로 필요없는 범위를 지워준다.
	compress.erase(std::unique(compress.begin(), compress.end()), compress.end());

	for (int& i : map)
		// lower_bound는 해당값보다 크거나 같은 값이 제일 처음 등장하는 index를 return한다.
		std::cout << std::lower_bound(compress.begin(), compress.end(), i) - compress.begin() << " ";

	return 0;
}