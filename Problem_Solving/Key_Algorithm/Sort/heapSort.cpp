#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#define MAX 100
using namespace std;

int Arr[MAX + 1];
bool Flag[10000];

/*
	MaxHeap : 부모 노드의 값이 자식 노드의 값보다 큰 완전이진트리
	MinHeap : 부모 노드의 값이 자식 노드의 값보다 작은 완전이진트리
*/
void Build_Heap() // 주어진 배열을 최대힙으로 만드는 함수이다.
{
	for (int Cur_Idx = 2; Cur_Idx <= MAX; Cur_Idx++) // 1번은 부모가 없으므로 2번부터 시작.
	{
		while (Cur_Idx > 1) // Root가 아닐 때 까지 반복하는데...
		{
			int Parent_Idx = Cur_Idx / 2;		// 부모 인덱스와 비교하기 위해서 부모 인덱스 값 설정.
			if (Arr[Cur_Idx] > Arr[Parent_Idx]) // 만약, 부모보다 값이 더 크다면??
			{
				swap(Arr[Cur_Idx], Arr[Parent_Idx]); // 값을 바꿔주고
				Cur_Idx = Parent_Idx;				 // 현재 Index도 부모 Index로 바꿔주고 비교 계속해서 진행.
			}
			else
				break; // 부모 Index가 더 큰 경우에는 변화가 일어나지 않으므로 종료.
		}
	}
}

/*
	왼쪽 자식 노드 번호 = 부모 노드의 번호 * 2,
	오른쪽 자식 노드 번호 = 부모 노드의 번호 * 2 + 1,

	왼쪽 자식의 노드번호 OR 오른쪽 자식의 노드 번호 / 2 = 부모 노드의 번호

	EX) 부모 노드 1 -> 왼쪽 2, 오른쪽 3, 부모 노드 2 -> 왼쪽 4, 오른쪽 5
*/
void Heapify(int Current, int N) // 제자리를 찾아가게 만드는 함수(첫 Index, 탐색범위)
{
	int Cur_Idx = Current;			   // 현재 Index
	int Left_Child = Current * 2;	   // 왼쪽 자식 Index번호
	int Right_Child = Current * 2 + 1; // 오른쪽 자식 Index번호

	if ((Left_Child <= N) && (Arr[Left_Child] > Arr[Cur_Idx]))
		Cur_Idx = Left_Child; // 왼쪽자식과 비교
	if ((Right_Child <= N) && (Arr[Right_Child] > Arr[Cur_Idx]))
		Cur_Idx = Right_Child; // 오른쪽자식과 비교

	if (Cur_Idx != Current) // 만약 변화가 생겼다면
	{
		swap(Arr[Cur_Idx], Arr[Current]); // Swap 후
		Heapify(Cur_Idx, N);			  // 재귀호출
	}
}

void HeapSort() // Main에서 호출되는 HeapSort
{
	Build_Heap(); // 최대힙으로 먼저 만들어주고
	for (int i = MAX; i >= 2; i--)
	{
		swap(Arr[i], Arr[1]); // Root와 정렬이 안된 마지막 Node 교환.
		Heapify(1, i - 1);	  // 제자리 찾아가기 !
	}
}

void Print()
{
	cout << "##########################################################################################################" << endl;
	int Cnt = 0;
	for (int i = 1; i <= MAX; i++)
	{
		printf("%3d ", Arr[i]);
		Cnt++;
		if (Cnt == 20)
		{
			Cnt = 0;
			cout << endl;
		}
	}
	cout << "##########################################################################################################" << endl;
	cout << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	srand((unsigned)time(NULL));
	for (int i = 1; i <= MAX;)
	{
		Arr[i] = rand() % 300 + 1;
		if (Flag[Arr[i]] == false)
		{
			Flag[Arr[i]] = true;
			i++;
		}
	}

	cout << "[ Initialize Array State ]" << endl;
	Print();
	HeapSort();
	cout << "[ After Sorting Array State]" << endl;
	Print();

	return 0;
}