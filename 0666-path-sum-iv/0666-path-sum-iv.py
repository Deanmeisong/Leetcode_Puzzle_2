class Solution(object):
    def pathSum(self, nums):
        self.sum, self.tree = 0, {}
        for x in nums:
            self.tree[x//10] = x%10
        self.dfs(nums[0]//10, 0)
        return self.sum
    def dfs(self, root, pre):
        cur = pre + self.tree[root]
        level, pos = root//10, root%10
        left, right = (level+1)*10 + 2*pos-1, (level+1)*10 + 2*pos
        if left not in self.tree and right not in self.tree:
            self.sum += cur
            return
        if left in self.tree: self.dfs(left, cur)
        if right in self.tree: self.dfs(right, cur)