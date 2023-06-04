# times = (출발지, 도착지, 소요시간), N = 전체 노드 개수, K = 출발지
import collections
import heapq


def networkDelayTime(times: List[List[int]], N: int, K: int) -> int:
    graph = collections.defaultdict(list)
    # 그래프 인접 리스트 구성
    for u, v, w in times:
        graph[u].append((v, w))
        
    # 큐 변수: [(소요 시간, 정점)], 즉 시작점에서 정점까지의 소요 시간
    # 초기값은 K부터이므로, 소요시간은 0이다.
    Q = [(0, K)]
    # 거리
    dist = collections.defaultdict(int)
    
    # 우선순위 큐 최솟값 기준으로 정점까지 최단 경로 삽입
    while Q:
        time, node = heapq.heappop(Q)
        if node not in dist:
            dist[node] = time # 항상 최솟값 세팅
            for v, w in graph[node]:
                alt = time + w
                heapq.heappush(Q, (alt, v))
                
    # 모든 노드의 최단 경로 존재 여부 판별
    if len(dist) == N:
        return max(dist.values())
    
    return -1