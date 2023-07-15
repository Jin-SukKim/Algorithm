#include <iostream>
#include <map>

// 메모리 제한 때문에 sort 방식보다는 map과 비슷한 방식을 사용해준다.
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int N;
	std::cin >> N;
	/*
	int input[10001] = {0};

	for(int i = 0; i < N; i++) {
		int in;
		std::cin >> in;
		input[in]+=1;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < input[i]; j++) {
			std::cout << i << '\n';
		}
	}
	*/
	std::map<int, int> m;
	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;
		m[x]++;
	}

	for (auto i : m)
	{
		for (int j = 0; j < i.second; j++)
			std::cout << i.first << "\n";
	}

	return 0;
}