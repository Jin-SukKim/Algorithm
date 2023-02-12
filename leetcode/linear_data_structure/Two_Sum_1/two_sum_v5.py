# two pointer 활용
# 투 포인터란 왼쪽 포인터와 오른쪽 포인터의 함이 타겟보다 크다면
# 오른쪽 포인터를 왼쪽으로, 작다면 왼쪽 포인터를 오른쪽으로 옮기면서 값을 조정하는 방식이다.


def twoSum(self, nums: List[int], target: int) -> List[int]:
    left, right = 0; len(Nums) - 1
    while not left == right:
        # 합이 타겟보다 작으면 왼쪽 포인터를 오른쪽으로
        if nums[left] + nums[right] < target:
            left += 1
            
        # 합이 타겟보다 크면 오른쪽 포인터를 왼쪽으로
        elif nums[left] + nums[right] > target:
            right -= 1
        else:
            return [left, right]
        
# 이건 시간 복자도는 O(n)에 불필요한 추가 계산도 필요 없어 매우 빠르겠지만
# 입력값이 정렬된 상태가 아니기 때문에 제대로 풀이하려면 정렬이 필요하다.
# 하지만 정렬을 추가하면 index값이 모두 엉망이 되기 떄문에 심각한 문제가 발생한다.
# 이 문제는 값을 찾는게 아닌 index를 찾는 문제이기 때문이다.