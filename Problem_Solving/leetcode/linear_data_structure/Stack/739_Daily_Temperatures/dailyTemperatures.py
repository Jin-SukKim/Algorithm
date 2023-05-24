def dailyTemperatures(T: list[int]) -> list[int]:
    answer = [0] * len(T)
    stack = []
    
    for i, cur in enumerate(T):
        # 현재 온도가 스택 값보다 높다면 정답 처리
        while stack and cur > T[stack[-1]]:
            last = stack.pop()
            answer[last] = i - last
        
        stack.append(i)
        
    return answer


temperatures = [73,74,75,71,69,72,76,73]
dailyTemperatures(temperatures)