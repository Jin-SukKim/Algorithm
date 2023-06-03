import collections

# 일정 그래프 반복
# 재귀가 아닌 동일한 구조를 반복으로 풀이해본다.
def findItinerary(tickets: List[List[str]]) -> List[str]:
    graph = collections.defaultdict(list)
    # 그래프 순서대로 구성
    for a, b in sorted(tickets):
        graph[a].append(b)
        
    route, stack = [], ['JFK']
    while stack:
        # 반복으로 스택을 구성하되 막히는 부분에서 풀어내는 처리
        # 막히는 부분은 이어지지 않고 끊어지는 부분
        while graph[stack[-1]]:
            stack.append(graph[stack[-1]].pop(0))      
        route.append(stack.pop())
        
    # 다시 뒤집어서 어휘 순 결과로
    return route[::-1]  

        