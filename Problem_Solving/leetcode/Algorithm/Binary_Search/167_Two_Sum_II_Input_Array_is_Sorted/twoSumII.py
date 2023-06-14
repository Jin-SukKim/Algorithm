# 투 포인터 (정렬된 배열을 input으로 받기에 사용 가능)
def twoSum(numbers: List[int], target: int) -> List[int]:
    left, right = 0, len(numbers) - 1
    while not left == right:
        # 합이 target보다 작다면 왼쪽 포인터를 이동
        if numbers(left) + numbers[right] < target:
            left += 1
        # 합이 target보다 크다면 오른쪽 포인터를 왼쪽으로 이동
        elif numbers[left] + numbers[right] > target:
            right -= 1
        else:
            # 이 문제에서 배열은 0이 아닌 1부터 시작하는 것으로 하기에 + 1해준다.
            return left + 1, right + 1 # 리턴 값 + 1