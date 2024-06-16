class Solution:
    def pathSum(self, nums: List[int]) -> int:
        sum, tree = 0, {}
        for x in nums: tree[x//10] = x%10
    
        def dfs(root, pre):
            nonlocal sum
            cur = tree[root] + pre
            lev, pos = root//10, root%10
            left, right = (lev+1)*10+2*pos-1, (lev+1)*10+2*pos
            if left not in tree and right not in tree:
                sum += cur
                return
            if left in tree: dfs(left, cur)
            if right in tree: dfs(right, cur)

        dfs(nums[0]//10, 0)
        return sum