# Counter로 계산 생략
import collections

def numJewelsInStones(self, jewels: str, stones: str) -> int:
    freqs = collections.Counter(S) # 돌 빈도수계산
    count = 0
    
    for char in J:
        count += freqs[char]
        
    return count