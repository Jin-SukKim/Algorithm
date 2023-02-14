# 파이썬은 특유의 슬라이싱을 활용하면 한줄로도 풀이가 가능하다.
def arraypairSum(self, nums: List[int]) -> int:
    return sum(sorted(nums)[::2])