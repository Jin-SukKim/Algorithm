class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

  

def diameterOfBinaryTree(root: TreeNode) ->int :
    longest: int = 0 
    def dfs(node: TreeNode) -> int:
        if not node:
            return -1
        # 왼쪽 오른쪽의각 리프 노드까지 탐색
        left = dfs(node.left)
        right = dfs(node.right)
        
        # 가장 긴 경로
        longest = max()
        # 상태값
        return max(left, right) + 1
    
    dfs(root)
    return longest