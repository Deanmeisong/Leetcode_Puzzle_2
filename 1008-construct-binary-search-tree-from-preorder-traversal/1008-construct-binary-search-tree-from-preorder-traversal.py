# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, A: List[int]) -> Optional[TreeNode]:
        def helper(i, j):
            if i == j: return None
            node = TreeNode(A[i])
            mid = bisect.bisect(A, A[i], i+1, j)
            node.left = helper(i+1, mid)
            node.right = helper(mid, j)
            return node
        return helper(0, len(A))