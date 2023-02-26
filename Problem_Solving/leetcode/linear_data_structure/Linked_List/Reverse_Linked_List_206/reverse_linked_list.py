# 재귀 구조로 뒤집기
def reverseList(self, head: ListNode) -> ListNode:
    def reverse(node: ListNode, prev: ListNode = None):
        if not node:
            return prev
        next, node.next = node.next, prev # 이전 prev 리스트를 next에 연결해준다.
        return reverse(next, node) # 재귀함수
    
    return reverse(head) # 재귀