class Solution(object):
    def maxA(self, n):
        dp = [0] * (n+1)
        for i in range(1,n+1):
            dp[i] = i
            for j in range(1, i-2):
                total = dp[j] + dp[j] * (i-j-2)
                dp[i] = max(dp[i], total)
        return dp[n]
        