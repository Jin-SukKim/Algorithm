import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# BFS 방식
def invertTree(root: TreeNode) -> TreeNode:
    queue = collections.dequee([root])
    
    while queue:
        node = queue.popleft()
        # 부모 노드부터 하향식 스왑(Top-Down 방식)
        if node:
            node.left, node.right = node.right, node.left
            
            queue.append(node.left)
            queue.append(node.right)
            
    return root