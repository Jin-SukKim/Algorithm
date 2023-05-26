class ListNode:
    def __init__(self, val, l = None, r = None):
        self.val = val
        self.l = l
        self.r = r
        
class MyCircularDeque:
    def __init__(self, k: int):
        # 왼쪽, 오른쪽 인덱스 역할
        self.head, self.tail = ListNode(None), ListNode(None)
        # 최대 길이, 현재 길이 정보
        self.k, self.len = k, 0
        self.head.right, self.tail.left = self.tail, self.head

    # 이중 연결 리스트에 신규 노드 삽입
    # 밑줄(_) : 내부에서 사용한다는 의미
    def _add(self, node: ListNode, new: ListNode):
        n = node.right
        node.right = new
        new.left, new.right = node, n
        n.left = new
        
    def _del(self, node: ListNode):
        n = node.right.right
        node.right = n
        n.left = node
        
    # 앞쪽에 노드를 추가
    def insertFront(self, value: int) -> bool:
        # dequeue가 꽉차면 False
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.head, ListNode(value))
        return True

    def insertLast(self, value: int) -> bool:
        # dequeue가 꽉차면 False
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.tail.left, ListNode(value))
        return True

    def deleteFront(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.head)
        return True

    def deleteLast(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.tail.left.left)
        return True

    def getFront(self) -> int:
        return self.head.right.val if self.len else -1

    def getRear(self) -> int:
        return self.tail.left.val if self.len else -1

    def isEmpty(self) -> bool:
        return self.len == 0
        
    def isFull(self) -> bool:
        return self.len == self.k
    
    
        
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()