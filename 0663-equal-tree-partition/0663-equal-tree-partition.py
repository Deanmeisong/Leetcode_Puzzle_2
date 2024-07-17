# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
        seen = []
        def dfs(node):
            if not node: return 0
            seen.append(node.val + dfs(node.left) + dfs(node.right))
            return seen[-1]
        total = dfs(root)
        seen.pop()
        for s in seen:
            if 2 * s == total: return True
        return False