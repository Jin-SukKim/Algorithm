# 첫 번째 수를 뺀 결과 키 조회

# 57ms, 15.3MB
# time-complexity O(n)
def twoSum(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
    
    # 키와 값을 바꿔서 딕셔너리로 저장
    for i, num in enumerate(nums):
        nums_map[num] = i
        
    # 타겟에서 첫번째 수를 뺀 결과를 키로 조회(index 찾기)
    for i, num in enumerate(nums):
        if target - num in nums_map and i != nums_map[target - num]:
            return [i, nums_map[target - num]]