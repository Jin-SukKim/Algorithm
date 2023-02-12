# 오름차순 풀이
def arrayPairSum(self, nums: List[int]) -> int:
    sum = 0
    pair = []
    nums.sort()

    for n in nums:
        # 앞에서부터 올므차순으로 페어를 만들어서 합 계산
        pair.append(n)
        if len(pair) == 2:
            sum += min(pai)
            pair = []

    return sum