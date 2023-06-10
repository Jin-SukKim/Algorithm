class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sortedArrayToBST(nums: List[int]) -> TreeNode:
    if not nums:
        return None
    
    mid = len(nums) // 2
    
    # 분할 정복으로 이진 검색 결과 트리 구성
    node = TreeNode(nums[mid])
    node.left = sortedArrayToBST(nums[:mid])
    node.right = sortedArrayToBST(nums[mid+1:])
    
    return node