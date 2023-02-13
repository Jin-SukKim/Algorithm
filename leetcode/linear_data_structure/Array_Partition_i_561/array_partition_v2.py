# 정렬된 배열의 인접 요소 페어의 min()값이란 결국
# 배열의 index의 짝수 번째 값과 같다.
# 간단히 짝수번째 값만 계산하면 된다.
def arrayPairSum(self, nums: List[int]) -> int:
    sum = 0
    nums.sort()

    for i, n in enumerate(nums):
        # 짝수 번째 값의 합 계산
        if i % 2 == 0:
            sums += n

    return sum