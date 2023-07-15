#include <iostream>
#include <vector>

std::vector<int> selectionSort(std::vector<int> &v, int &N)
{
	for (int i = 0; i < N; i++)
	{
		int index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (v[index] > v[j])
				index = j;
		}
		std::swap(v[index], v[i]);
	}
	return v;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int N;
	std::cin >> N;
	std::vector<int> v(N);
	for (int i = 0; i < N; i++)
		std::cin >> v[i];

	v = selectionSort(v, N);
	
	for (int &i : v)
		std::cout << i << " ";
	return 0;
}