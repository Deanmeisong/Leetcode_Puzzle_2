class Solution(object):
    def matrixScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        res = m * (1<<(n-1))
        for j in range(1, n):
            same = sum(grid[i][0] == grid[i][j] for i in range(m))
            res += max(same, m-same) * (1<<(n-1-j))
        return res