# XOR 풀이

# 단 1개의 숫자를 찾는데 적당한 연산자는 XOR이다.
# XOR은 입력값이 서로 다르면 True, 서로 동일한 경우 False가 되는 논리 게이트 연산자다.
# 이것을 십진수에 적용할 수 있따.
# ex) 0 ^ 0 = 0, 4 ^ 0 = 4, 4 ^ 4 = 0
def singleNumber(nums: List[int]) -> int:
    result = 0
    for num in nums:
        result ^= num
    
    return result