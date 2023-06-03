# 큐를 이용한 반복 구조

# 모든 인접 Edge를 추출하고 도착점인 Vertex를 큐에 삽입
def iterative_bfs(start_v):
    discovered = [start_v]
    queue = [start_v]   # 최적화는 위해 dequeue도괜찮다.
    while queue:
        v = queue.pop(0)
        # 인접 Edge를 추출해 다음 도착 Vertex 삽입
        for w in graph[v]:
            # 가본적이 없는 vertex라면
            if w not in discovered:
                discovered.append(w)
                queue.append(w)
    return discovered

# 재귀함수로는 BFS를 구현할 수 없다.
    
    
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
