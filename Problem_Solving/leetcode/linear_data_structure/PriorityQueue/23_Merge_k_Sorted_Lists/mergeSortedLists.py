import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    # heapq 모듈 : Min Heap을 지원해 값이 작은 순서대로 pop() 할 수 있다.
    # 중복 값을 넣을 수는 없다.
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        root = result = ListNode(None)
        heap = []
        
        # 각 연결 리스트의 루트를 힙에 저장
        for i in range(len(lists)):
            if lists[i]:
                # heappush() 함수에서 중복 값은 에러가 발생하기에 방지하기 위해 연결 리스트의 순서를 삽입한다.
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
                
        # 힙 추출 이후 다음 노드는 다시 저장
        while heap:
            node = heapq.heappop(heap)
            idx = node[1]
            result.next = node[2]
            
            result = result.next
            if result.next:
                heapq.heappush(heap, (result.next.val, idx, result.next))
                
        return root.next
        
        