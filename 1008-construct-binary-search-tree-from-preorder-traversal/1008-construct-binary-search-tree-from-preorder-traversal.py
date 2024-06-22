# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    i = 0
    def bstFromPreorder(self, A, bound = float('inf')):
        if self.i == len(A) or A[self.i] > bound:
            return None
        root = TreeNode(A[self.i])
        self.i += 1
        root.left = self.bstFromPreorder(A, root.val)
        root.right = self.bstFromPreorder(A, bound)
        return root
        