import collections

# deque를 이용한 최적화
# pop(0)은 O(n)인데 deque는 O(1)이다.
def isPalindrome(self, s: str) -> bool:
    # 자료형 deque로 선언
    strs = collections.deque()
    
    for char in s:
        if char.isalnum():
            strs.append(char.lower())
            
    while len(strs) > 1:
        if strs.popleft() != strs.pop():
            return False
    
    return True