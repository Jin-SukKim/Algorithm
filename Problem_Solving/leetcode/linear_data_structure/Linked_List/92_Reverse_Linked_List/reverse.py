def reverseBetween(head: ListNode, m: int, n: int) -> ListNode:
    # 예외 처리
    if not head or m == n:
        return head
    
    root = start = ListNode(None)
    root.next = head
    
    # start, end 지점
    for _ in range(m - 1):
        start = start.next
    end = start.next
    
    # 반복하면 서 노드 차례대로 뒤집기
    for _ in range(n - m):
        tmp, start.next, end.next = start.next, end.next, end.next.next
        start.next.next = tmp
        
    return root.next