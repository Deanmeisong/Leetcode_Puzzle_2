class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        dp = [[n]*n for _ in range(n)]
        for x, y in mines:
            dp[x][y] = 0
        
        for i in range(n):
            l = r = u = d = 0
            for j in range(n):
                k = n - j - 1
                l = 0 if dp[i][j] == 0 else l+1
                dp[i][j] = min(dp[i][j], l)
                r = 0 if dp[i][k] == 0 else r+1
                dp[i][k] = min(dp[i][k], r)
                u = 0 if dp[j][i] == 0 else u+1
                dp[j][i] = min(dp[j][i], u)
                d = 0 if dp[k][i] == 0 else d+1
                dp[k][i] = min(dp[k][i], d)
        
        ans = 0
        for i in range(n):
            for j in range(n):
                ans = max(ans, dp[i][j])
        
        return ans