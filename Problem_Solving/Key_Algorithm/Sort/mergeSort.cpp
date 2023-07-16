#include <iostream>
#include <vector>

// 2개의 배열 v[left...mid]와 v[mid+1...right] 합치기
void merge(std::vector<int>& v, int l, int mid, int r)
{
	// 왼쪽 배열 길이(왼쪽 배열에 mid가 포함되어 있기에 1을 더해준다.)
	int left = mid - l + 1;
	// 오른쪽 배열 길이
	int right = r - mid;

	// 배열 생성
	// v[left...mid]
	std::vector<int> leftV(left);
	// v[mid+1...right]
	std::vector<int> rightV(right);

	// 기존 배열을 두 개의 배열로 나눠준다.
	for (int i = 0; i < left; i++)
		// v[left...mid]
		leftV[i] = v[l + i];

	for (int i = 0; i < right; i++)
		// v[mid+1...right]
		rightV[i] = v[mid + 1 + i];

	// 분할된 왼쪽 배열 포인터
	int i = 0;
	// 분할된 오른쪽 배열 포인터
	int j = 0;
	// 정렬된 배열에 대한 포인터
	// 실제로 원래 배열 자체를 나누진 않았기 때문에 l부터 시작
	int k = l;

	// 분할된 배열 정렬하며 합치기
	// 이미 새로운 배열을 생성해 분할해줬기 때문에 temp등 임시 배열을 생성하지 않고
	// 바로 기존 배열에 정렬된 값을 입력해도 된다.
	while (i < left && j < right)
	{
		if(leftV[i] < rightV[j])
		{
			v[k] = leftV[i];
			i++;
		}
		else
		{
			v[k] = rightV[j];
			j++;
		}
		k++;
	}

	// 이미 정렬되어서 남아 있는 값 복사
	while (i < left)
	{
		v[k] = leftV[i];
		i++;
		k++;
	}
	while (j < right)
	{
		v[k] = rightV[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int>& v, int l, int r)
{
	if (l < r)
	{
		// overflow 방지
		int mid = l + (r - l) / 2;
		// 반으로 분할해준다.
		mergeSort(v, l, mid);
		mergeSort(v, mid + 1, r);
		// 분할한 배열을 합쳐준다.
		merge(v, l, mid, r);
	}
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

	mergeSort(v, 0, N-1);
	for(int& i : v)
		std::cout << i << "\n";
	return 0;
}