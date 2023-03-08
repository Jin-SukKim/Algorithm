# 반복 구조로 스왑

# 구조 자체를 바꿔준다.
def swapPairs(self, head: ListNode) -> ListNode:
    root = prev = ListNode(None)
    prev.next = head
    
    while head and head.next:
        # b가 a(head)를 가리키도록 할당
        b = head.next
        head.next = b.next
        b.next = head
        
        # prev가 b를 가리키도록 할당
        prev.next = b
        
        # 다음번 비교를 위해 이동
        head = head.next
        prev = prev.next.next
        
    return root.next