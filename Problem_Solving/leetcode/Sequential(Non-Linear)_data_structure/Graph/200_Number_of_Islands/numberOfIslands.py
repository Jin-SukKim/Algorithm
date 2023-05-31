def numIslands(self, grid: List[List[str]]) -> int:
    # 재귀 호출에서 모두 빠져나오면 섬 하나를 발견한 것으로 간주
    def dfs(i, j):
        # 더 이상 땅이 아닌 경우 종료
        if i < 0 or i >= len(grid) or \
            j < 0 or j >= len(grid[0]) or \
                grid[i][j] != '1': 
                    return
        
        # 이미 방문한 곳은 1이 아닌 값으로 마킹해 다시 계산하는 경우를 방지
        # 일종의 가지치기
        grid[i][j] = '0'
        
        # 동서남북 탐색(재귀함수)
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i, j - 1)
    
    # 예외 처리
    if not grid:
        return 0
    
    count = 0
    
    # 행렬(Matrix) 입력값인 행(Row), 열(Cols) 단위로 육지를 찾는다. 
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            # 육지(1)을 발견하면 dfs()를 호출해 탐색을 시작한다)
            if grid[i][j] == '1':
                dfs(i, j)
                # 모든 육지 탐색 후 카운트 1 증가
                count += 1
                
    return count