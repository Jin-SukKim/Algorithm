#include <iostream>
#include <stack>
#include <vector>

// 앞에서 뒤로 가는 for loop안에 비교를 위해 뒤에서 앞으로 가는 for loop를
// 추가해도 답이 나오겠지만 stack을 활용하면 좀 더 최적화가 가능하다.
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	// 비교할 값들을 저장할 stack
	std::stack<int> stack;
	std::vector<int> res(n);
	for (int i = n-1; i >= 0; i--)
	{
		// i의 오른쪽에 비교할 값이 있지만 v[i]보다 작다면 stack에서 빼준다.
		while (!stack.empty() && stack.top() <= v[i])
			stack.pop();

		// stack이 비어 있다면 비교할 값이 없거나 다 작은 값들만 있다는 의미로 -1
		if (stack.empty())
			res[i] = -1;
		else
			res[i] = stack.top();

		// 무조건 stack에 넣어줘 v[i]보다 큰 수 중에서 가장 왼쪽에 있는 수를 출력하도록 한다.
		stack.push(v[i]);
	}

	for (int& i : res)
		std::cout << i << " ";

	return 0;
}