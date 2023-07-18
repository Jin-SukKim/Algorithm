#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

void printStack(std::stack<char>& stack)
{
	while (!stack.empty())
	{
		std::cout << stack.top();
		stack.pop();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	// std::cin.tie(0);

	// LIFO이므로 뒤집혀서 출력한다.
	std::stack<char> stack;
	bool tag = false;

	std::string s;
	std::getline(std::cin, s);

	for (char &c : s)
	{
		if (!tag && c == ' ')
		{
			printStack(stack);
			std::cout << " ";
		}
		else if (c == '<')
		{
			printStack(stack);
			std::cout << c;
			tag = true;
		}
		else if (tag && c == '>')
		{
			std::cout << c;
			tag = false;
		}
		else if (tag)
			std::cout << c;
		else
			stack.push(c);
	}

	printStack(stack);
	return 0;
}