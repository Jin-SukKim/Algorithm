class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def insertionSort(head: ListNode) -> ListNode:
    # cur : 정렬을 끝낸 대상, parent: root를 가르키는 노드
    cur = parent = ListNode(None)
    # head : 정렬해야 할 대상
    while (head):
        while cur.next and cur.next.val < head.val:
            cur = cur.next
        
        cur.next, head.next, head = head, cur.next, head.next
        
        if head and cur.val > head.val:
            cur = parent
    return cur.next