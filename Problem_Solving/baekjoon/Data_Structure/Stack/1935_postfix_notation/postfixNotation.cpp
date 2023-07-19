#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;

	std::stack<char> op;
	std::string res;
	for (char &c : s)
	{
		if (std::isalpha(c))
			res += c;
		
		// "(..)"괄호안의 모든 걸 빼준다.
		else if (c == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				res += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (c == '*' || c == '/')
		{
			// '*'와 '/'는 같은 '/','/'와 우선순위가 같으므로 해당 연산자가 나올 때 까지 pop해준다.
			while (!op.empty() && (op.top() == '*' || op.top() == '/'))
			{
				res += op.top();
				op.pop();
			}
			op.push(c);
		}
		else if (c == '+' || c == '-')
		{
			while (!op.empty() && op.top() != '(')
			{
				res += op.top();
				op.pop();
			}
			op.push(c);
		}
		else
		{
			op.push(c);
		}
	}

	// 나머지 연산자들
	while (!op.empty())
	{
		res += op.top();
		op.pop();
	}

	std::cout << res;

	return 0;
}