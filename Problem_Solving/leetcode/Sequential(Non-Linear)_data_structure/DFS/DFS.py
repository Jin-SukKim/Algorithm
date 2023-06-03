# 재귀 구조로 구현
# 정점 v의 모든 인접 유향(Directed) Edge들을 반복
def recursive_dfs(v, discovered=[]):
    # 방문했던 Vertex
    discovered.append(v) 
    for w in graph[v]:
        # 방문하지 않았다면
        if w not in discovered:
            discovered = recursive_dfs(w, discovered) # 방문하며 재귀
    
    return discovered


# 스택을 이용한 반복 구조로 표현
def iterative_dfs(start_v):
    discovered = []
    stack = [start_v]
    while stack:
        v = stack.pop()
        if v not in discovered:
            discovered.append(v)
            for w in graph[v]:
                stack.append(w)
                
    return discovered

# 두 방식은 결과 순서가 다르다.
# 재귀는 사전식 순서(Lexicographical Order)로 방문한다면
# stack을 이용한 반복은 역순으로 방문한다.
if __name__ == "__main__":
    graph = {
        1: [2, 3, 4],
        2: [5],
        3: [5],
        4: [],
        5: [6, 7],
        6: [],
        7: [3]
    }
