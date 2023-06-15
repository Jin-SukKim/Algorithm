# 자연어 처리에서도 널리 쓰이는 해밍 거리는 두 정수 또는 두 문자열의 차이를 말한다.
# ex) karolin과 kathrin의 차이는 3이고 1011101과 1001001은 2다.
# 문자열의 경우 다른 자리의 문자 개수가 되며, 이진수의 경우 다른 위치의 비트 개수다.

# XOR 연산을 하면, 다른 위치는 1이 될 것이다.
# 이후 1의 전체 개수를 return하면 된다.

def hammingDistance(x: int, y: int) -> int:
    return bin(x ^ y).count('1')