# 리스트 변환

# 팰린드롬 여부를 판별하기 위해 앞 뒤로 모두 추출할 수 있는 자료구조를 사용한다.
def isPalindrome(self, head: ListNode) -> bool:
    q: List = []
    
    if not head:
        return True
    
    node = head
    # 리스트 변환
    while node is not None:
        q.append(node.val)
        node = node.next
        
    # 팰린드롬 판별
    while len(q) > 1:
        # pop 함수에 index 지정이 가능하다.
        if q.pop(0) != q.pop(): # 느리다.
            return False
        
    return True