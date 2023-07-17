#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPS(std::string &s)
{
	// LIFO이므로 뒤집혀서 출력한다.
	std::stack<char> stack;

	for (char& c : s)
	{
		// ')'를 만나면 stack에 넣은 '('하나를 빼 한 쌍을 완성한다.
		if (c == ')')
		{
			if (stack.empty())
				return false;
			stack.pop();
		}
		// '('을 stack에 넣는다.
		else
			stack.push(c);
	}

	return stack.empty();
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	// cin은 '\n'을 처리하지 않고 입력 버퍼에 남겨둔다.
	std::cin >> n;

		while (n--)
	{
		std::string s;
		std::cin >> s;

		if (isPS(s))
			std::cout << "YES"
					  << "\n";
		else
			std::cout << "NO"
					  << "\n";
	}

	return 0;
}