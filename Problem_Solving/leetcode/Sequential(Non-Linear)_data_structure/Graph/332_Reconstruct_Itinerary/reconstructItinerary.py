import collections


def findItinerary(tickets: List[List[str]]) -> List[str]:
    graph = collections.defaultdict(list)
    # 어휘 순으로 방문해야 하기에 그래프 순서대로 구성 
    for a, b in sorted(tickets):
        graph[a].append(b)
        
    route = []
    def dfs(a):
        # 첫 번째 값을 읽어어휘 순 방문
        while graph[a]:
            # pop()으로 재귀 호출하며 결과에 추가했기에 역순으로 담긴다.
            # pop()으로 해당 경로를 삭제하며 추가해 재방문 방지
            dfs(graph[a].pop(0))
        route.append(a)
        
    dfs("JFK")    
    # 다시 뒤집어 어휘 순 결과로
    return route[::-1]
        