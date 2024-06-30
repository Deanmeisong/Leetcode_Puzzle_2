# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0

    def maxAncestorDiff(self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.dfs(root, root.val, root.val)
        return self.ans

    def dfs(self, root: TreeNode, curMax: int, curMin: int) -> None:
        if root is None:
            return
        self.ans = max(self.ans, max(abs(root.val - curMax), abs(root.val - curMin)))
        curMax = max(curMax, root.val)
        curMin = min(curMin, root.val)
        self.dfs(root.left, curMax, curMin)
        self.dfs(root.right, curMax, curMin)
        