#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

// 앞에서 뒤로 가는 for loop안에 비교를 위해 뒤에서 앞으로 가는 for loop를
// 추가해도 답이 나오겠지만 stack을 활용하면 좀 더 최적화가 가능하다.
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> v(n);
	// 나온 빈도수를 비교
	std::unordered_map<int, int> freq;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		v[i] = x;
		freq[x]++;

	}

	// 비교할 값들을 저장할 stack
	std::stack<int> stack;
	std::vector<int> res(n);
	
	for (int i = n-1; i >= 0; i--)
	{
		// stack에 값이 있으면 현재 위치(i)와 그 오른쪽 값들의 빈도수 비교
		while (!stack.empty() && freq[stack.top()] <= freq[v[i]])
			stack.pop();
		
		// 비교할 값이 없거나 현재 위치(i)보다 많이 나온 값이 없으면
		if (stack.empty())
			res[i] = -1;
		else
			res[i] = stack.top();

		stack.push(v[i]);
	}

	for (int& i : res)
		std::cout << i << " ";

	return 0;
}