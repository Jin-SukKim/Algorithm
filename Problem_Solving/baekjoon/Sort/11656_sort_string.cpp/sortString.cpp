#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void merge(std::vector<std::string>& v, int l, int mid, int r)
{
	int left = mid - l + 1;
	int right = r - mid;

	std::vector<std::string> leftV(left);
	std::vector<std::string> rightV(right);

	for (int i = 0; i < left; i++)
		leftV[i] = v[l + i];
	
	for (int i = 0; i < right; i++)
		rightV[i] = v[mid + 1 + i];

	int pl = 0;
	int pr = 0;
	int sort = l;

	while (pl < left && pr < right)
	{
		// 접두사인 string의 맨 첫 단어만 비교
		if (leftV[pl][0] < rightV[pr][0])
		{
			v[sort++] = leftV[pl++];
		}

		else
		{
			v[sort++] = rightV[pr++];
		}
	}

	while (pl < left)
		v[sort++] = leftV[pl++];

	while (pr < right)
		v[sort++] = rightV[pr++];
}

void mergeSort(std::vector<std::string> &v, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(v, l, mid);
		mergeSort(v, mid + 1, r);
		merge(v, l, mid, r);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;

	int end = s.length();
	std::vector<std::string> words(end);

	for (int i = 0; i < end; i++)
	{
		words[i] = s.substr(i, end - i);
	}

	//mergeSort(words, 0, end-1);
	std::sort(words.begin(), words.end());

	for (auto &word : words)
		std::cout << word << '\n';

	return 0;
}