import collections


class Solution:
    # Memoization을 이용한 간단한 다이나믹 프로그래밍
    def majorityElement(self, nums: List[int]) -> int:
        counts = collections.defaultdict(int)
        for num in nums:
            if counts[num] == 0:
                counts[num] = nums.count(num)
                
            if counts[num] > len(nums) // 2:
                return num
    
    # 분할 정복
    def majorityElement2(self, nums: List[int]) -> int:
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]
        
        half = len(nums) // 2
        a = self.majorityElement2(nums[:half])
        b = self.majorityElement2(nums[half:])
        
        return [b, a][nums.count(a) > half]