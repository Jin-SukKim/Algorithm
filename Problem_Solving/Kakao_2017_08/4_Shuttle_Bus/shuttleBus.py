# 입력값 전처리 및 대기 시각 처리
def solution(n: int, t: int, m: int, timeTable: List[str]) -> str:
    # 입력값 분 단위 전처리
    # 문자형으로 들어오는 입력값을 쉽게 계산 가능향 형태로 변경해준다.
    # Epoch Time으로 변경하면 좋으나 여긴 시/분만 있는 형태이기에 간단히 분 단위로 변경해준다.
    timeTable = [
        int(time[:2]) * 60 + int(time[3:])
        for time in timeTable
    ]
    timeTable.sort()
    
    # 셔틀 운행 횟수 n에 따라 대기자가 m만큼 탑승할 수 있도록 해준다.
    # 버스 탑승 시각 설정은 2가지 경우에 따른다.
    # 1. 먼저 온 사람이 먼저 탈 것이므로 출발 시각보다 먼저 온 사람은 큐 연산으로 항상 탑승하게 한다.
    # 2. 더 이상 탈 사람이 없다면 최대한 늦게 오는 것이 목표이므로 현재 버스가 온 시각으로 설정한다.
    current = 540
    
    for _ in range(n):
        for _ in range(m):
            # 대기가 있는 경우 1분 전 도착
            if timeTable and timeTable[0] <= current:
                candidate = timeTable.pop(0) - 1
            # 대기가 없는 경우 정시 도착
            else:
                candidate = current
                
        current += t
        
    # 시, 분으로 다시 변경
    h, m = divmod(candidate, 60)
    return str(h).zfill(2) + ':' + str(m).zfill(2)