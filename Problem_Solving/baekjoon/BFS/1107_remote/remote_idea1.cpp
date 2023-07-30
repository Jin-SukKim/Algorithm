#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string n;
	int m;
	std::cin >> n >> m;

	if (n == "100")
	{
		std::cout << 0;
		return 0;
	}

	std::vector<bool> remote(10, false);
	for (int i = 0; i < m; i++)
	{
		int j;
		std::cin >> j;
		remote[j] = true;
	}

	std::string current;
	int count = n.length();
	for (char &c : n)
	{
		if (remote[c - 48])
		{
			int diff = 10;
			int target = c - 48;
			for (int i = 0; i < 10; i++)
			{
				if (!remote[i])
				{
					if (target)
						diff = std::min(diff, target - (i % target));
					else
						diff = std::min(diff, i);
				}
			}
			target = target - diff > 0 ? target - diff : target + diff;
			current += (target + 48);
			continue;
		}
		current += c;
	}

	int diff = std::abs(std::stoi(n) - std::stoi(current));
	count += diff;

	std::cout << count;
	return 0;
}
