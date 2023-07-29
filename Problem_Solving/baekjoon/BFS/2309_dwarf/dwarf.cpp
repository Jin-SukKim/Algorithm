#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &nums, int l, int mid, int r)
{
	int leftLength = mid - l + 1;
	int rightLength = r - mid;

	std::vector<int> leftSub(leftLength);
	std::vector<int> rightSub(rightLength);

	for (int i = 0; i < leftLength; i++)
		leftSub[i] = nums[l + i];

	for (int i = 0; i < rightLength; i++)
		rightSub[i] = nums[mid + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < leftLength && j < rightLength)
	{
		if (leftSub[i] < rightSub[j])
			nums[k++] = leftSub[i++];
		else
			nums[k++] = rightSub[j++];
	}

	while (i < leftLength)
		nums[k++] = leftSub[i++];

	while (j < rightLength)
		nums[k++] = rightSub[j++];
}

void mergeSort(std::vector<int> &nums, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid + 1, r);
		merge(nums, l, mid, r);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::vector<int> nums(9);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		std::cin >> nums[i];
		sum += nums[i];
	}
		
	mergeSort(nums, 0, 8);

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - nums[i] - nums[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						std::cout << nums[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}