# 반복 구조로 뒤집기
# 속도는 재귀함수보다 조금 빠르나 메모리를 많이 차지한다.
def reverseList(self, head: ListNode) -> ListNode:
    node, prev = head, None
    
    while node :
        # node.next에 이전 리스트 연결
        next, node.next = node.next, prev
        prev, node = node, next
        
    return prev

