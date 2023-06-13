
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 내장 함수를 이용
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # 연결리스트 -> 파이썬 리스트
        p = head
        lst: List = []
        while p:
            lst.append(p.val)
            p = p.next
            
        # 정렬
        lst.sort()
        
        # 파이썬 리스트 -> 연결 리스트
        p = head
        for i in range(len(lst)):
            p.val = lst[i]
            p = p.next
        
        return head