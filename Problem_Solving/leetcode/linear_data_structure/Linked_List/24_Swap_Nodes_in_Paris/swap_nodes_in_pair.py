# 노드 구조는 유지하되 값만 변경하는 방법

# 노드가 가진 값이 1개뿐이라 간단하지만
# 값이 여러개인 경우(ex: int, float etc) 이 방법은 사용하기 어렵다.
def swapPairs(self, head: ListNode) -> ListNode:
    cur = head
    
    while cur and cur.next:
        # 값만 교환
        cur.val, cur.next = cur.next.val, cur.val
        cur = cur.next.next
        
    return head