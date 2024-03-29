# 정렬이 되어 있지만 피벗을 기준으로 입력값이 돌아간 상태이다.
# 피벗이 뭔지 모르는 상태이므로, 피벗을 먼저 찾아준다.
# 이 문젱에서 피벗은 가장 작은 값의 index다.
def search(nums: List[int], target: int) -> int:
    # 예외 처리
    if not nums:
        return -1
    
    # 최솟값을 찾아 피벗 설정
    # 이진 겁색으로 최솟값을 찾는 알고리즘
    left, right = 0, len(nums) - 1
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] > nums[right]:
            left = mid + 1
        else:
            right = mid
            
    pivot = left
    
    # 피벗 기준 이진 검색
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        mid_pivot = (mid + pivot) % len(nums)
        
        if nums[mid_pivot] < target:
            left = mid + 1
        elif nums[mid_pivot] > target:
            right = mid - 1
        else:
            return mid_pivot
    
    return -1