#include <iostream>
#include <string>
#include <algorithm>

bool compare(char& a, char& b)
{
	return a > b;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	
	std::sort(s.begin(), s.end(), compare);
	std::cout << s;
	return 0;
}