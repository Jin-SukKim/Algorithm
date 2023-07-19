#include <iostream>
#include <string>
#include <cctype>

// 카이사르 암호기법
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string code;
	std::getline(std::cin, code);

	std::string encrypt;
	for (char& c : code)
	{	
		if (c == ' ')
			encrypt += ' ';
		else if (std::isalpha(c))
		{
			int e;
			if ('a' <= c && c <= 'z')
			{
				e = (c - 'a' + 13) % 26 + 'a';
			}
			else if ('A' <= c && c <= 'Z')
			{
				e = (c - 'A' + 13) % 26 + 'A';
			}
			encrypt += e;
		}
		else
			encrypt += c;
	}

	std::cout << encrypt;
	return 0;
}