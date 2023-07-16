#include <iostream>
#include <vector>
#include <algorithm>

// 평균적으로 O(n log n), 최악의 경우 O(n^2)
// v = 배열, l = v.begin(), r = v.end() - 1
void quickSort(std::vector<int> &v, int l, int r)
{
	// best case
	if (l >= r)
		return;

	// overflow 방지하며 중간 길이 구하기
	// r + l을 한 뒤 2로 나누는 경우 r + l에서 int의 범위를 벗어날 가능성이 있다.
	int middle = l + (r - l) / 2;
	// 왼쪽, 오른쪽 포인터
	int pl = l, pr = r;

	// pivot 값
	int pivot = v[middle];

	// <= 작거나 같을때까지 비교하면 left ptr가 right ptr보다 오른쪽에 간다.
	// 즉, 두 포인터가 서로 엇갈린다.
	while (pl <= pr)
	{
		// 왼쪽값이 pivot보다 작으면 왼쪽 포인터를 움직인다.
		// pivot 값보다 큰 값을 찾을 때까지 포인터를 움직인다.
		while (v[pl] < pivot) 
			pl++;
		// 오른쪽 값이 pivot보다 크다면 오른쪽 포인터를 움직인다.
		// pivot 값보다 작은 값을 찾을 때까지 포인터를 움직인다.
		while (pivot < v[pr])
			pr--;

		// 결국 pivot의 위치에 left, right 포인터가 모였다가 한 칸씩 더 움직여 서로 엇갈린다.
		if (pl <= pr) {
			std::swap(v[pl], v[pr]);
			pl++;
			pr--;
		}
	}
	
	// right포인터가 left 포인터보다 왼쪽에 있다.
	// pivot을 중심으로 왼쪽 배열[l...pr]을 정렬해준다.
	if (l < pr)
		quickSort(v, l, pr);
	// left포인터가 right포인터보다 오른쪽에 있다.
	// pivot을 중심으로 오른쪽 배열[pl...r]을 정렬해준다.
	if (pl < r)
		quickSort(v, pl, r);
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