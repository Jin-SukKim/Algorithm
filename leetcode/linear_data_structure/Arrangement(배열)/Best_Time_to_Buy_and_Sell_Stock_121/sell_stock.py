# BFS, 가장 기본적인 풀이법
def maxPorfit(self, prices: List[int]) -> int:
    max_price = 0

    for i, price in enumerate(prices):
        for j in range(i, len(prices)):
            max_price =  max(prices[j] - price, max_price)

    return max_price