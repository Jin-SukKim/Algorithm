import heapq

# 파이썬은 최소 힙만 제공하기에 음수로 저장한다.
def findKthlargest(nums: List[int], k: int) -> int:
    heap = list()
    for n in nums:
        heapq.heappush(heap, -n)
        
    for _ in range(1, k):
        heapq.heappop(heap)
        
    return -heapq.heappop(heap)