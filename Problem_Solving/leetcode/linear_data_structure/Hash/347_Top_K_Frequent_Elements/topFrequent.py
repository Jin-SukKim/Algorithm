# counter를 이용한 음수 순 추출
import collections
import heapq

def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    freqs = collections.Counter(nums)
    freqs_heap = [] # priority queue
    # 힙에 음수로 삽입
    for f in freqs:
        # 빈도 수를 key로 해 삽입해준다.
        # 파이썬 heapq 모듈은 최소 힙(Min-Heap)만 지원하기에 음수로 저장
        heapq.heappush(freqs_heap, (-freqs[f], f))
        
    topk = list()
    # k번 만큼 추출, 최소 힙(Min Heap)이므로 가장 작은 음수 순으로 추출
    for _ in range(k):
        topk.append(heapq.heappop*(freqs_heap)[1])
        
    return topk