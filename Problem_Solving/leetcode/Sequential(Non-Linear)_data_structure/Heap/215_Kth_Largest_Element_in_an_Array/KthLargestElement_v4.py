# 정렬을 이용해 풀어준다.
def findKthlargest(nums: List[int], k: int) -> int:
    # 큰 값부터 역순으로 정렬
    return sorted(nums, reverse=True)[k - 1]