# 조회 구조 개선
def twoSum(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
    
    # 하나의 for문으로 dict의 저장과 조회를 통합해 구조를 개선
    for i, num in enumerate(nums):
        if target - num in nums_map:
            return [nums_map[target - num], i]
        
        nums_map[num] = i