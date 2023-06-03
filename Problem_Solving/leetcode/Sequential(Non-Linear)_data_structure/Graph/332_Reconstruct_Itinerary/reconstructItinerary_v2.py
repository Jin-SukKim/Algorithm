import collections

# 스택 연사능로 큐 연산 최적화 시도
def findItinerary(tickets: List[List[str]]) -> List[str]:
    graph = collections.defaultdict(list)
    # 그래프를 뒤집어서 구성
    for a, b in sorted(tickets, reverse=True):
        graph[a].append(b)
        
    route = []
    def dfs(a):
        # 마지막값을 읽어 어휘 순 방문
        while graph[a]:
            # 큐는 pop(0)을 하면 O(n)이 걸리지만 스택은 O(1)이다.
            dfs(graph[a].pop())
        route.append(a)
        
    dfs("JFK")    
    # 다시 뒤집어 어휘 순 결과로
    return route[::-1]
        