# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findClosestLeaf(self, root: Optional[TreeNode], k: int) -> int:
        self.start = None
        graph = collections.defaultdict(list)

        def dfs(node, parent, val):
            if node:
                if node.val == val:
                    self.start = node
                if parent:
                    graph[node].append(parent)
                    graph[parent].append(node)
                dfs(node.left, node, val)
                dfs(node.right, node, val)

        dfs(root, None, k)
        
        q = collections.deque([self.start])
        seen = set(q)
        
        while q:
            node = q.popleft()
            if node:
                if node.left is None and node.right is None:
                    return node.val
                for nei in graph[node]:
                    if nei not in seen:
                        seen.add(nei)
                        q.append(nei)
        
        return 0