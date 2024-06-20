# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root: return (-1, None)
            ld, l = dfs(root.left)
            rd, r = dfs(root.right)
            if ld == rd: return(ld+1, root)
            return (ld + 1, l) if ld > rd else (rd + 1, r)
        return dfs(root)[1]
