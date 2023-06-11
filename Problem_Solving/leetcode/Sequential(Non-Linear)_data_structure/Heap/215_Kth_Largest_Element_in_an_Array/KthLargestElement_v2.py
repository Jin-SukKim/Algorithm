import heapq


def findKthlargest(nums: List[int], k: int) -> int:
    # heapify()는 자료구조가 힙 특성을 만족하도록 바꿔주는 연산이다
    heapq.heapify(nums)
    
    for _ in range(len(nums) - k):
        heapq.heappop(nums)
        
    return heapq.heappop(nums)