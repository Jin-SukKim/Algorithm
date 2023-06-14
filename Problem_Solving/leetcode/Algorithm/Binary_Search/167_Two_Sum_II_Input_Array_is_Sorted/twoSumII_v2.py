
import bisect

# 이진 검색으로 풀이하면 검색 log n을 n번 반복하므로 시간 복잡도가 O(n log n)이 된다.
# 투 포인터 방식인 O(n)보다 이진 검색이 더 느리다.


def twoSum(numbers: List[int], target: int) -> List[int]:
    for k, v in enumerate(numbers):
        left, right = k + 1, len(numbers) - 1
        expected = target - v
        # 이진 검색으로 나머지 값 판별
        while left <= right:
            mid = left + (right - left) // 2
            if numbers[mid] < expected:
                left = mid + 1
            elif numbers[mid] > expected:
                right = mid - 1
            else:
                return k + 1, mid + 1

# 파이썬 내장 함수인 이진 검색으로 풀이


def twoSum(self, numbers: List[int], target: int) -> List[int]:
    for k, v in enumerate(numbers):
        expected = target - v
        # 왼쪽 범위를 제한 하는 파라미터 lo, 오른쪽 범위를 제한하는 hi
        # bisect.bisect_left(a, x, lo=0, hi=len(a))
        i = bisect.bisect_left(numbers, expected, k + 1)
        if i < len(numbers) and numbers[i] == expected:
            return k + 1, i + 1
