#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> map(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		map[i] = std::make_pair(x, y);
	}

	std::sort(map.begin(), map.end(), compare);
	for (auto& p : map)
		std::cout << p.first << " " << p.second << "\n";
	

	return 0;
}