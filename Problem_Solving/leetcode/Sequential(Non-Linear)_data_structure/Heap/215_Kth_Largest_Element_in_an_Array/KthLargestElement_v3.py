import heapq


def findKthlargest(nums: List[int], k: int) -> int:
    # heapq는 n번째 큰 값을 추출하는 기능을 제공한다.
    return heapq.nlargest(k, nums)[-1]