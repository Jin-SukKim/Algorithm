import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
# 반복 부조로 DFS 후위 순회 방식
# v1~3는 전위(Pre-Order) 순회 형태이고 이 방법은 후위(Post-Order)순회 방식이다.
# 단지 탐색 순서만 달라진다.)
def invertTree(root: TreeNode) -> TreeNode:
    stack = collections.deque([root])
    
    while stack:
        node = stack.pop()
        # 부모 노드부터 Top-Down 스왑
        if node:
            stack.append(node.left)
            stack.append(node.right)
            
            node.left, node.right = node.right, node.left
            
    return root