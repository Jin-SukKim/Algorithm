class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 파이썬 방식
def invertTree(self, root: TreeNode) -> TreeNode:
    # 재귀 방식인데 맨 밑부터 백트래킹해가며 스왑하는 Bottom-Up 방식
    if root:
        root.left, root.right = \
            invertTree(root.right), invertTree(root.left)
        return root
    return None