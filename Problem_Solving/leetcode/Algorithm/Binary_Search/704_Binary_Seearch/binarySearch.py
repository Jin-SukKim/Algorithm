# 4가지 방법

# 재귀 풀이
def search1(nums: List[int], target: int) -> int:
    def binary_search(left, right):
        if left <= right:
            mid = left + (right - left) // 2

            if nums[mid] < target:
                return binary_search(mid + 1, right)
            elif nums[mid] > target:
                return binary_search(left, mid - 1)
            else:
                return mid

        else:
            return -1

    return binary_search(0, len(nums) - 1)

# 반복 풀이


def search2(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            return mid
        
    return -1

# 이진 검색 모듈(파이썬은 이진 검색 알고리즘을 지원하는 bisect 모듈이 있다.)
def search3(nums: List[int], target: int) -> int:
    index = bisect.bisect_left(nums, target)
    
    if index < len(nums) and nums[index] == target:
        return index
    else:
        return -1
    
# 이진 검색을 사용하지 않는 index 풀이
def search4(nums: List[int], target: int) -> int:
    # 해당 값의 index를 찾아해는 함수
    try:
        return nums.index(target)
    # 존재하지 않는 값은 Error가 발생하므로 예외처리
    except ValueError:
        return -1