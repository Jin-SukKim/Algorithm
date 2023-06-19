import collections

# 피보나치 수열과 거의 유사한 형태다

# 재귀 brute-forc로 풀이는 가능하나 시간초과이다.
def rob(nums: List[int]) -> int:
    def _rob(i: int) -> int:
        if i < 0:
            return 0
        # 바로 옆집은 훔칠 수 없으니 현재 집과 옆집 중 최댓값을 구하고,
        # 한 집 건넛집까지의 최댓값과 현재 집의 숫자값과의 합을 구해서
        # 두 수 중 더 높은 값이 정답이 된다.
        return max(_rob(i - 1), _rob(i - 2) + nums[i])
    return _rob(len(nums) - 1)

# 타뷸레이션


def rob2(nums: List[int]) -> int:
    if not nums:
        return 0
    if len(nums) <= 2:
        return max(nums)

    dp = collections.OrderedDict()
    dp[0], dp[1] = nums[0], max(nums[0], nums[1])

    for i in range(2, len(nums)):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    return dp.popitem()[1]
