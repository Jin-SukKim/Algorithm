# 오름차순 풀이

# min()을 합산했을 때 최대를 만드는 것은 결국 min()의 값이 되도록 커야된다는 뜻이다.
# 즉 입력된 배열을 정렬한 후 오름차순이나 내림차순으로 인접 요소 페어(Adjacent Elements Pair)을
# 만들면 가장큰 페어들을 만들 수 있다.
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