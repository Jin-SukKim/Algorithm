#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	// A부터 순서대로 영대문자에 대입되는 값
	std::vector<double> nums(n);
	for (int i = 0; i < n; i++)
		std::cin >> nums[i];

	std::stack<double> operand;

	// 후위 표기식
	for (int i = 0; i < s.length(); i++)
	{
		if (std::isalpha(s[i]))
		{
			operand.push(nums[s[i] - 'A']);
		}
		else
		{
			if (!operand.empty())
			{
				double num = operand.top();
				operand.pop();
				if (s[i] == '+')
				{
					num = operand.top() + num;
				}
				else if (s[i] == '-')
				{
					num = operand.top() - num;
				}
				else if (s[i] == '*')
				{
					num = operand.top() * num;
				}
				else if (s[i] == '/')
				{
					num = operand.top() / num;
				}
				operand.pop();
				// 계산한 값을 다시 넣어줘 다음 계산에서도 사용할 수 있게 한다.
				operand.push(num);
			}
		}
	}
	
	std::cout << std::fixed << std::setprecision(2) << operand.top();
	return 0;
}