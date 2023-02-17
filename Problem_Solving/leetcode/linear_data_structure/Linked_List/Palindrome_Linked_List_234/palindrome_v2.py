# 최적화하기
# 동적 배열로 구성된 리스트는 맨 앞 element를 가져오기엔 shifting 작업 때문에 느리다.
# Deque는 이중 연결 리스트 구조로 양방향에서 value를 뽑는데 O(1)로 매우 빠르다
def isPalindrome(self, head: ListNode) -> bool:
    # 데크 자료형 선언
    q: Deque = collections.deque()
    
    if not head:
        return True
    
    node = head
    while node is not None:
        q.append(node.val)
        node = node.next
        
    while len(q) > 1:
        if q.popleft() != q.pop():
            return False
        
    return True    