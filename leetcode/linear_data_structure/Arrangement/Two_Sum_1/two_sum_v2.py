# using in for searching
# 모든 조합을 비교하지 않고 타겟에서 첫 번쨰 값을 뺸 값 traget - n이
# 존재하는지 탐색해보기

# in은 파이썬 내부 함수로 구현되어 있어 BFS에 비해 매우 빠르다.

# time-complexity O(n^2)
def twoSum(self, nums: list[int], target: int) -> list[int]:
    for i, n in enumerate(nums):
        complement = target - n
        
        if complement in nums[i + 1:]:
            return [nums.index(n), nums[i + 1:].index(complement) +  (i + 1)]