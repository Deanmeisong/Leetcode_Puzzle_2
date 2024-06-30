# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.ans = 0

    def maxAncestorDiff(self, root):
        if root is None:
            return 0
        self.dfs(root, root.val, root.val)
        return self.ans

    def dfs(self, root, curMax, curMin):
        if root is None:
            return
        self.ans = max(self.ans, max(abs(root.val - curMax), abs(root.val - curMin)))
        curMax = max(curMax, root.val)
        curMin = min(curMin, root.val)
        self.dfs(root.left, curMax, curMin)
        self.dfs(root.right, curMax, curMin)
        