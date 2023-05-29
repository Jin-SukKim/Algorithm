# defaultdict을 이용해 비교 생략
import collections


def numJewelsInStones(self, jewels: str, stones: str) -> int:
    freqs = collections.defaultdict(int)
    
    # 비교 없이 돌 빈도 수 계산
    for char in S:
        freqs[char] += 1
        
    for cahr in J:
        count += freqs[char]
        
    return count