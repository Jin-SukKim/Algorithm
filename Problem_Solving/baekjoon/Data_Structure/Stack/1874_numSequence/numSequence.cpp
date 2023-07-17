#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::stack<int> stack;
	int i = 1;
	std::vector<char> res;
	for (int j = 0; j < n; j++)
	{
		int x;
		std::cin >> x;

		// stack에 x까지 1부터 안넣은 값들을 넣어준다.
		while (i <= x)
		{
			stack.push(i++);
			res.push_back('+');
		}

		// 맨 위의 값이 x와 같다면 빼준다.
		if (x == stack.top())
		{
			stack.pop();
			res.push_back('-');
		}
		// 맨 위의 값과 같지 않다면 다른 값을 빼줘야 할텐데
		// 이 값을 빼면 나중에 필요할 수 있지만 존재하지 않아 수열을 만들 수 없다
		// ex) stack{3, 4}, s = 3이라 3과 4를 모두 빼준 뒤 그 다음 4을 찾는 다면
		// stack은 이미 비어있어 수열을 만들 수 없다.
		else
		{
			std::cout << "NO";
			return 0;
		}
	}
	
	for (char& c : res)
		std::cout << c << '\n';

	return 0;
}