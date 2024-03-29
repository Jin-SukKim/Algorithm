import collections
import heapq


def findCheapestPrice(n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
    graph = collections.defaultdict(list)
    # 그래프 인접 리스트 구성
    for u, v, w in flights:
        graph[u].append((v,w))
        
    # 큐 변수: [(가격, 정점, 남은가능 경유지 수)]
    Q = [(0, src, K)]
    
    # 우선순위 큐 최솟값 기준을 도착점까지 최소 비용 판별
    while Q:
        price, node, k = heapq.heappop(Q)
        if node == dst:
            return price
        # K 이내일 때만 경로를 추가해 K를 넘어서는 경로는 탐색되지 않게 한다.
        if k >= 0:
            for v, w in graph[node]:
                alt = price + w
                heapq.heappush(Q, (alt, v, k - 1))
                
    return -1
    