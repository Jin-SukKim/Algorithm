#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
{
	return a.first < b.first;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, std::string>> map(n);
	for (int i = 0; i < n; i++)
	{
		int age;
		std::string name;
		std::cin >> age >> name;
		map[i] = std::make_pair(age, name);
	}

	std::stable_sort(map.begin(), map.end(), compare);

	for (auto &p : map)
		std::cout << p.first << " " << p.second << "\n";

	return 0;
}