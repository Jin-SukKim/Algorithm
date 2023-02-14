# 왼쪽 값과 오른쪽 값 따로 곱한뒤 서로 곱해주기
def productExceptSelf(self, nums: List[int]) -> List[int]:
    out = []
    p = 1

    # 왼쪽 곱셈
    for i in  range(0, len(nums)):
        out.append(p)
        p = p * nums[i]

    p = 1
    # 왼쪽 곱셈 결과에 오른쪽 값을 차례대로 곱셈
    for i in range(len(nums) - 1, 0 - 1, -1):
        out[i] = out[i] * p
        p = p * nums[i]

    return out