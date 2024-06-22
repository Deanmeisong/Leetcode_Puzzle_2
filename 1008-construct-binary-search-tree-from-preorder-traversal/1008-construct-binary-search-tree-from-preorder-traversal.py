# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def bstFromPreorder(self, A):
        return self.dfs(A[::-1], float('inf'))
    def dfs(self, A, bound):
        if not A or A[-1] > bound: return None
        root = TreeNode(A.pop())
        root.left = self.dfs(A, root.val)
        root.right = self.dfs(A, bound)
        return root