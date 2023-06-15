
def hammingWeight(n: int) -> int:
    count = 0
    while n:
        # 1을 뺸 값과 AND 연산 횟수 측정
        n &= n -1
        count += 1
        
    return count

# 파이썬 방식
def hammingWeight2(n: int) -> int:
    return bin(n).count('1')