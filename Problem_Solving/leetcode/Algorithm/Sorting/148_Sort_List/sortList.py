class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# merge sort
class Solution:
    # 길이가 얼마가 되든 재귀 호출을 통해 l1의 포인터를 이동하면서 정렬해 return
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            # 정렬
            if l1.val > l2.val:
                l1, l2 = l2, l1
            l1.next = self.mergeTwoLists(l1.next, l2)
        
        # l1값을 우선으로 return
        return l1 or l2
    
    # 굳이 l1 or l2를 비교하지 않고 l1이 None이라면 미리 스왑하는 방식
    def mergeTwoLists2(self, l1: ListNode, l2: ListNode) -> ListNode:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists2(l1.next, l2)
        
        return l1
        
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not (head and head.next):
            return head
        
        # 런너 기법 활용
        # slow는 한 칸씩, fast는 두 칸씩 앞으로 이동한다.
        # fast가 맨 끝에 도달했을 때 slow는 중앙에 도착한다.
        # half는 slow의 바로 이전 값으로 한다.
        half, slow, fast = None, head, head
        while fast and fast.next:
            half, slow, fast = slow, slow.next, fast.next.next
        
        # 마지막에 half.next = None으로 half 위치를 기준으로 연결 리스트를 끊어준다.
        half.next = None
        
        # 연결리스트를 끊었으므로 연결리스트가 분할된다.
        # 분할 재귀 호출
        l1 = self.sortList(head) # 시작 노드
        l2 = self.sortList(slow) # 탐색을 통해 발견한 중앙 지점
        
        # 최종적으로 단일 아이템으로 쪼갰던 것을 다시 합쳐준다.
        # 합칠때 크기 비교를 통해 정렬하면서 이어 붙인다.
        return self.mergeTwoLists(l1, l2)