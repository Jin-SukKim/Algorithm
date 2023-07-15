#include <iostream>
#include <vector>
#include <algorithm>

int sort(std::vector<int> &v, int& l, int& r)
{
	// overflow 방지하며 중간 길이 구하기
	int middle = l + (r - l) / 2;
	// 왼쪽, 오른쪽 포인터
	int pl = l, pr = r;

	// pivot 값
	int pivot = v[middle];

	while (pl < pr)
	{
		// 왼쪽값이 pivot보다 작으면 왼쪽 포인터를 움직인다.
		// pivot 값보다 큰 값을 찾을 때까지 포인터를 움직인다.
		while (v[pl] < pivot) 
			pl++;
		// 오른쪽 값이 pivot보다 크다면 오른쪽 포인터를 움직인다.
		// pivot 값보다 작은 값을 찾을 때까지 포인터를 움직인다.
		while (pivot < v[pr])
			pr--;

		if (pl < pr)
			std::swap(v[pl], v[pr]);
	}
	return pr;
}


void quickSort(std::vector<int> &v, int l, int r)
{
	if (l >= r)
		return;
		
	if (l < r)
	{
		// 중간값을 pivot으로 정해 정렬해준다.
		int pivot = sort(v, l, r);
		// 배열을 두개로 쪼갠다.
		// pivot을 중심으로 왼쪽 배열
		quickSort(v, l, pivot - 1);
		// pivot을 중심으로 오른쪽 배열
		quickSort(v, pivot + 1, r);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int N, k;
	std::cin >> N >> k;
	std::vector<int> v(N);
	for (int i = 0; i < N; i++)
		std::cin >> v[i];

	quickSort(v, 0, v.size()-1);

	std::cout << v[N - k];

	return 0;
}