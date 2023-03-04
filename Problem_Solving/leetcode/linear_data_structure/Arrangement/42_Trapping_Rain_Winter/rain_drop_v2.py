# stack을 활용한 풀이

def trap(self, height: List[int]) -> int:
    stack = []
    volume = 0
    
    for i in range(len(height)):
        # 현재 높이가 이전 높이보다 높을 떄,
        # 즉 꺽이는 부분 변곡점(Inflection Point)을 기준으로
        # 격차만큼 물 높이(volume)를 채운다.
        while stack and height [i] > height[[stack[-1]]]:
            # 변곡점을 만나면 스택에서 꺼낸다
            top = stack.pop()
            
            if not len(stack):
                break
            
            # 이전과의 차이만큼 물 높이를 채운다
            distance = i - stack[-1] - 1
            waters = min(height[i], height[stack[-1]]) - height[top]
            
            volume += distance * waters
        
        # 높이는 고정된 형태가 아니라 들쑥날쑥하기 때문에 계속 스택으로 채워 나간다.
        stack.append(i)
    
    return volume