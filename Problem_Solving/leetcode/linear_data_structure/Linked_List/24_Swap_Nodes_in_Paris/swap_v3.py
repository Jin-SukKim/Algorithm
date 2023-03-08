# 재귀 구조로 스왑

# 백트래킹되면서 연결 리스트가 이어진다.
def swapPairs(self, head: ListNode) -> ListNode:
    if head and head.next:
        p = head.next
        
        # 스왑된 값 리턴 받음
        head.next = self.swapPairs(p.next)
        p.next = head
        return p
    
    return head