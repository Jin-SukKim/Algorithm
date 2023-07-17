#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	// std::cin.tie(0);

	int n;
	// cin은 '\n'을 처리하지 않고 입력 버퍼에 남겨둔다.
	std::cin >> n;
	// getline() 함수를 사용해야 하므로 입력 버퍼를 비워준다.
	std::cin.ignore();
	// LIFO이므로 뒤집혀서 출력한다.
	std::stack<char> stack;

	while (n--)
	{
		std::string s;
		std::getline(std::cin, s);

		for (char &c : s)
		{
			if (c == ' ')
			{
				while (!stack.empty())
				{
					std::cout << stack.top();
					stack.pop();
				}
				std::cout << " ";
			}
			else
				stack.push(c);
		}

		while (!stack.empty())
		{
			std::cout << stack.top();
			stack.pop();
		}
		std::cout << "\n";
	}

	return 0;
}