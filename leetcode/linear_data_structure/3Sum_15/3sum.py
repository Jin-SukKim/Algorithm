# BFS 

# 제일 간단하지만 시간이 많이 거리는 문제로
# leetcode 사이트에서 timeout으로 풀이에 실패한다.
def threeSum(self, nums: List[int]) -> List[List[int]]:
    results = []

    # 앞뒤로 같은 값이 있을 경우, 쉽게 처리하기 위해 정렬한다. O(n log n)
    nums.sort()

    # BFS n^3 반복
    # i, j, k 각각의 포인터가 이동하면서 i+j+k=0 을 찾는다.
    for i in range(len(nums) -2):
        # 중복된 값 건너뛰기
        if i > 0 and nums[i] == nums[i - 1]:
            continue
            
        for j in range(i + 1, len(nums) - 1):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue

            for k in range(j + 1, len(nums)):
                if k > j + 1 and nums[k] == nums[k - 1]:
                    continue

                if nums[i] + nums[j] + nums[k] == 0:
                    results.append([nums[i], nums[j], nums[k]])

    return results