# two pointer와 제일 높은 벽을 이용한다.

def trap(self, height: List[int]) ->int:
    if not height:
        return 0
    
    # 물높이
    volume  = 0
    # 좌우 포인터
    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]
    
    while left < right:
        # 제일 높은 기둥을 기준으로 좌우로 물을 채워준다. 
        left_max, height_max = max(height[left], left_max),
                                max(height[right], right_max)
        
        # 더 높은 쪽을 향해 투 포인터 이동
        # 좌우 기둥 최대 높이가 현재 높이와의 차이만큼 물높이를 더한다.
        # 적어도 낮은 쪽은 그만큼 항상 채워진다.
        # 좌우 어느쪽이든 낮은 쪽은 높은 쪽을 향해서 포인터가 가운데로 점점 이동한다.
        
        # 오른쪽이 크다면 왼쪽이 이동
        if left_max <= right_max:
            volume += left_max - height[left]
            left += 1
        # 왼쪽이 크다면 오른쪽이 이동
        else:
            volume += right_max - height[right]
            right -= 1
    
    # 결국 최대 지점에서 좌우 포인터가 서로 만나게 되며 최종 물양이 정해진다.
    return volume