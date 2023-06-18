# 재귀 구조 Brute-Force ( 가장 느린 방식)
# 만약 n = 5라면 총 15번의 연산을 진행한다.
def fib(N: int) -> int:
    if N <= 1:
        return N
    return fib(N - 1) + fib(N - 2)


# 다이나믹 프로그래밍의 하향식 풀이(Memoization)
class Solution:
    dp = collection.defaultdic(int)

    # 만약 n = 5라면 총 9번의 연산을 진행한다.
    # 이미 fib(2)나 fib(3)의 값이 있기에 연산을 진행하지 않고 바로 return하기 때문이다.
    def fib(self, N: int) -> int:
        if N <= 1:
            return N

        # 저장해둔 값을 찾는다면 바로 return
        if self.dp[N]:
            return self.dp[N]

        # 이미 계산한 값은 저장
        self.dp[N] = self.fib(N - 1) + self.fib(N - 2)

    # 다이나믹 프로그래밍의 상향식 풀이(Tabulation)
    # 일차원 선형 구조라 복잡하지 않고, 구조 자체도 단순해 이해가 쉽다. (속도도 빠르다)
    def fib2(self, N: int) -> int:
        self.dp[0] = 0
        self.dp[1] = 1

        # 반복으로 풀이해 작은 값부터 직접 계산하면서 Tabulation한다.
        for i in range(2, N + 1):
            self.dp[i] = self.dp[i - 1] + self.dp[i - 2]
        return self.dp[N]

    # 두 변수만 이용해 공간 절약(공간 복잡도 = O(1))
    def fib3(self, N: int) -> int:
        # dictionary대신 단순 배열이나 변수 2개만 사용
        x, y = 0, 1
        for i in range(0, N):
            x, y = y, x + y
        return x

    # 행렬 (O(log n) 시간복잡도를 가졌다)
    # 선형대수 관점에서 행렬의 n승을 계산하는 방법으로 Numpy 모듈을 사용했다.
    def fib(n):
        M = np.matrix([[0, 1], [1, 1]])
        vec = np.array([[0], [1]])

        return np.matrix(M ** n, vec)[0]
