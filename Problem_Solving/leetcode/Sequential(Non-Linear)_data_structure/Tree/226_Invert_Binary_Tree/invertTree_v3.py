import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# DFS 방식


def invertTree(root: TreeNode) -> TreeNode:
    stack = collections.deque([root])
    
    while stack:
        node = stack.pop()
        # 부모 노드부터 Top-Down 스왑
        if node:
            node.left, node.right = node.right, node.left
            
            stack.append(node.left)
            stack.append(node.right)
            
    return root
