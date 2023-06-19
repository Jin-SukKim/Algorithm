import sys


def maxSubArray(nums: List[int]) -> int:
    for i in range(1, len(nums)):
        nums[i] += nums[i - 1] if nums[i - 1] > 0 else 0
    return max(nums)

# 카데인 알고리즘
# 1977년에 제안된 컴퓨터 과학 알고리즘 문제로서 제인 카데인이 O(n)에 풀이가 가능하도록
# 고안한 카데인 알고리즘 해법이 있다.
# 최대 서브 배열을 찾기 위해 어디서 시작되는지를 찾는 문제 O(n^2) 풀이에서 각 단계마다
# 최댓값을 담아 어디서 끝나는지를 찾는 문제 O(n) 풀이로 치환해서 풀이했다.
def maxSubArray2(nums: List[int]) -> int:
    best_sum = -sys.maxsize
    current_sum = 0
    for num in nums:
        current_sum = max(num, current_sum + num)
        best_sum = max(best_sum, current_sum)
        
    return best_sum