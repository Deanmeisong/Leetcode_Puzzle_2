# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        return self.dfs(root)[1]
    def dfs(self, root):
        if not root: return (-1, None)
        ld, l = self.dfs(root.left)
        rd, r = self.dfs(root.right)
        if ld == rd: return(ld+1, root)
        return (ld + 1, l) if ld > rd else (rd + 1, r)

        