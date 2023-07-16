#include <iostream>
#include <set>
#include <string>

struct compare
{
	bool operator()(const std::string &a, const std::string &b) const
	{
		if (a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	}
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::set<std::string, compare> map;
	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		map.insert(s);
	}

	for (auto &p : map)
		std::cout << p << "\n";

	return 0;
}